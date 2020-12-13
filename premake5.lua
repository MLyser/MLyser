workspace "MLyser"
    architecture "x86_64"
    configurations { "Debug", "Release", "Production"}

    filter "configurations:Debug"
        defines "MLZ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "MLZ_RELEASE"
        optimize "On"

    filter "configurations:Production"
        defines "MLZ_PRODUCTION"
        symbols "Off"
        optimize "Full"

outputdir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

project "MLyser"
    location "MLyser"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    filter "action:vs*"  -- for Visual Studio actions
        pchheader "mlzpch.h"
        pchsource "%{prj.location}/src/mlzpch.cpp"

    filter "action:not vs*"  -- for everything else
        pchheader "src/mlzpch.h"
    filter {}

    files
    {
        "%{prj.location}/src/**.h",
        "%{prj.location}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.location}/src",
        "%{prj.location}/vendor/spdlog/include",
        "%{prj.location}/vendor/qt/frameworks",
        "%{prj.location}/vendor/qt/include",
        "%{prj.location}/vendor/libtorch/include",
        "%{prj.location}/vendor/libtorch/include/torch/csrc/api/include"
    }

    -- MacOS specific way of adding include directories (Fuckin' Xcode)
    sysincludedirs
    {
        "%{prj.location}/src",
        "%{prj.location}/vendor/spdlog/include",
        "%{prj.location}/vendor/qt/frameworks",
        "%{prj.location}/vendor/qt/include",
        "%{prj.location}/vendor/libtorch/include",
        "%{prj.location}/vendor/libtorch/include/torch/csrc/api/include"
    }

    libdirs
    {
        "%{prj.location}/vendor/qt/frameworks",
        "%{prj.location}/vendor/qt/lib",
        "%{prj.location}/vendor/libtorch/lib"
    }

    -- OSCommon library linkage
    links
    {
        "c10",
        "torch",
        "torch_cpu"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        links
        {
            "Qt5Core",
            "Qt5Gui",
            "Qt5Widgets",
            "Qt5DBus",
            "Qt5PrintSupport",
        }

        defines
        {
            "MLZ_PLATFORM_WINDOWS"
        }

        postbuildcommands
        {
            "Xcopy %{prj.location}vendor\\qt\\qpa-plugins\\%{cfg.system} %{wks.location}bin\\" .. outputdir .. "\\%{prj.name}\\plugins\\platforms /i /e /Y",
            "copy %{prj.location}vendor\\qt\\lib\\*.dll %{wks.location}bin\\" .. outputdir .. "\\%{prj.name}",
            "copy %{prj.location}vendor\\libtorch\\lib\\*.dll %{wks.location}bin\\" .. outputdir .. "\\%{prj.name}"
        }

    filter "system:macosx"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.15"

        links
        {
            "QtCore.framework",
            "QtGui.framework",
            "QtWidgets.framework",
            "QtDBus.framework",
            "QtPrintSupport.framework"
        }

        defines
        {
            "MLZ_PLATFORM_MACOSX"
        }

        frameworkdirs
        {
            "%{prj.location}/vendor/qt/frameworks"
        }

        postbuildcommands
        {
            "cp -rf  %{prj.location}/vendor/qt/qpa-plugins/%{cfg.system}/. %{wks.location}/bin/" .. outputdir .. "/%{prj.name}/plugins/platforms/",
            "cp -rf  %{prj.location}/vendor/qt/frameworks/. %{wks.location}/bin/" .. outputdir .. "/%{prj.name}/",
            "cp -rf  %{prj.location}/vendor/libtorch/lib/*.dylib %{wks.location}/bin/" .. outputdir .. "/%{prj.name}/",
        }

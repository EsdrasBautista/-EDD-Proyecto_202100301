cmake_minimum_required(VERSION 3.16)

project(Fase2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES Fase2_es_GT.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Fase2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        admin.h admin.cpp admin.ui
        userint.h userint.cpp userint.ui
        crearuser.h crearuser.cpp crearuser.ui
        listaEnlazadaArbol.h
        listaEnlazadaArbol.cpp
        perfil.h perfil.cpp perfil.ui
        buscar.h buscar.cpp buscar.ui
        solicitudes.h solicitudes.cpp solicitudes.ui
        GestionarSoli.h
        GestionarSoli.cpp
        nodoMatriz.h
        nodoMatriz.cpp
        PilaSoli_R.h
        PilaSoli_R.cpp
        listasoli_e.h listasoli_e.cpp
        listasoli_R.h
        listasoli_R.cpp
        listaPublicaciones.h
        listaPublicaciones.cpp
        publicaciones.h publicaciones.cpp publicaciones.ui
        crearpublicacion.h crearpublicacion.cpp crearpublicacion.ui
        nodoPublicacion.h
        nodoPublicacion.cpp
        buscaradmin.h buscaradmin.cpp buscaradmin.ui
        cargaradmin.h cargaradmin.cpp cargaradmin.ui
        reportesadmin.h reportesadmin.cpp reportesadmin.ui
        listaAmistades.h
        listaAmistades.cpp
        SimplePublicacion.h
        SimplePublicacion.cpp
        modificaradmin.h modificaradmin.cpp modificaradmin.ui
        arbolB.h
        arbolB.cpp
        comentaru.h comentaru.cpp comentaru.ui
        vercomentarios.h vercomentarios.cpp vercomentarios.ui
        verarbolcomentarios.h verarbolcomentarios.cpp verarbolcomentarios.ui
        reportesuser.h reportesuser.cpp reportesuser.ui
        relacionAmistad.h
        relacionAmistad.cpp
        sha256.h
        sha256.cpp
        nodosMerk.h
        nodosMerk.cpp
        globalesV.h
        merkle.h
        merkle.cpp
        reportegrafo.h reportegrafo.cpp reportegrafo.ui
        reporteady.h reporteady.cpp reporteady.ui
        reportemerkle.h reportemerkle.cpp reportemerkle.ui
        nodoHuffmann.h
        nodoHuffmann.cpp
        Huffman.h
        Huffman.cpp
        reporteamistaduser.h reporteamistaduser.cpp reporteamistaduser.ui
        reporteadyuser.h reporteadyuser.cpp reporteadyuser.ui







    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Fase2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(Fase2 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Fase2
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(Fase2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Fase2)
endif()
set_target_properties(Fase2 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Fase2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Fase2)
endif()

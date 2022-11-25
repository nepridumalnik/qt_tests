set(TARGET main)

set(SOURCES
    main.cpp
    lineedit.cpp
    popupcombobox.cpp
    lineedit.ui
)

set(LIBRARIES
    Qt5::Widgets
    Qt5::Core
    # ${lineedit_ui}
)

# QT5_WRAP_UI(lineedit_ui lineedit.ui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# message("-- lineedit_ui: ${lineedit_ui}")

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})

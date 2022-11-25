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
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})

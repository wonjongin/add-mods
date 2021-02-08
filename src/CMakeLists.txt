file(GLOB_RECURSE UI_FILES *.ui)
file(GLOB_RECURSE CODE_FILES *.cpp)
# file(GLOB_RECURSE HEADER_FILES *.h)
qt5_wrap_ui(UI_HEADERS ${UI_FILES})


if (WIN32)
  add_executable(add-mods WIN32
    ${UI_HEADERS}
    ${CODE_FILES}
  )
elseif (APPLE)
  add_executable(add-mods MACOSX_BUNDLE
    ${UI_HEADERS}
    ${CODE_FILES}
  )
elseif (UNIX AND NOT APPLE)
  add_executable(add-mods 
    ${UI_HEADERS}
    ${CODE_FILES}
  )
endif()

target_link_libraries(add-mods
  Qt5::Widgets
)

file(GLOB_RECURSE UI_FILES *.ui)
file(GLOB_RECURSE CODE_FILES *.cpp)
# file(GLOB_RECURSE HEADER_FILES *.h)
qt5_wrap_ui(UI_HEADERS ${UI_FILES})

add_executable(add-mods 
  ${UI_HEADERS}
  ${CODE_FILES}
  # ${HEADER_FILES}
)

target_link_libraries(add-mods
  Qt5::Widgets
)

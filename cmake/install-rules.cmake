install(
    TARGETS example-vc_exe
    RUNTIME COMPONENT example-vc_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()

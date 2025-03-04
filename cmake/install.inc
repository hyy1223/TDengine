IF (TD_LINUX)
  SET(TD_MAKE_INSTALL_SH "${TD_COMMUNITY_DIR}/packaging/tools/make_install.sh")
  INSTALL(CODE "MESSAGE(\"make install script: ${TD_MAKE_INSTALL_SH}\")")
  INSTALL(CODE "execute_process(COMMAND chmod 777 ${TD_MAKE_INSTALL_SH})")
  INSTALL(CODE "execute_process(COMMAND ${TD_MAKE_INSTALL_SH} ${TD_COMMUNITY_DIR} ${PROJECT_BINARY_DIR} Linux ${TD_VER_NUMBER})")
ELSEIF (TD_WINDOWS)
  IF (TD_POWER)
    SET(CMAKE_INSTALL_PREFIX C:/PowerDB)
  ELSE ()
    SET(CMAKE_INSTALL_PREFIX C:/TDengine)
  ENDIF ()

  INSTALL(DIRECTORY ${TD_COMMUNITY_DIR}/src/connector/go     DESTINATION connector)
  INSTALL(DIRECTORY ${TD_COMMUNITY_DIR}/src/connector/nodejs DESTINATION connector)
  INSTALL(DIRECTORY ${TD_COMMUNITY_DIR}/src/connector/python DESTINATION connector)
  INSTALL(DIRECTORY ${TD_COMMUNITY_DIR}/src/connector/C\# DESTINATION connector)
  INSTALL(DIRECTORY ${TD_COMMUNITY_DIR}/tests/examples DESTINATION .)
  INSTALL(DIRECTORY ${TD_COMMUNITY_DIR}/packaging/cfg DESTINATION .)
  INSTALL(FILES ${TD_COMMUNITY_DIR}/src/inc/taos.h DESTINATION include)
  INSTALL(FILES ${TD_COMMUNITY_DIR}/src/inc/taoserror.h DESTINATION include)
  INSTALL(FILES ${LIBRARY_OUTPUT_PATH}/taos.lib DESTINATION driver)
  INSTALL(FILES ${LIBRARY_OUTPUT_PATH}/taos.exp DESTINATION driver)
  INSTALL(FILES ${LIBRARY_OUTPUT_PATH}/taos.dll DESTINATION driver)

  IF (TD_POWER)
    INSTALL(FILES ${EXECUTABLE_OUTPUT_PATH}/power.exe DESTINATION .)
  ELSE ()
    INSTALL(FILES ${EXECUTABLE_OUTPUT_PATH}/taos.exe DESTINATION .)
    INSTALL(FILES ${EXECUTABLE_OUTPUT_PATH}/taosdemo.exe DESTINATION .)
  ENDIF ()

  #INSTALL(TARGETS taos RUNTIME DESTINATION driver)
  #INSTALL(TARGETS shell RUNTIME DESTINATION .)
  IF (TD_MVN_INSTALLED)
    INSTALL(FILES ${LIBRARY_OUTPUT_PATH}/taos-jdbcdriver-2.0.35-dist.jar DESTINATION connector/jdbc)
  ENDIF ()
ELSEIF (TD_DARWIN)
  SET(TD_MAKE_INSTALL_SH "${TD_COMMUNITY_DIR}/packaging/tools/make_install.sh")
  INSTALL(CODE "MESSAGE(\"make install script: ${TD_MAKE_INSTALL_SH}\")")
  INSTALL(CODE "execute_process(COMMAND chmod 777 ${TD_MAKE_INSTALL_SH})")
  INSTALL(CODE "execute_process(COMMAND ${TD_MAKE_INSTALL_SH} ${TD_COMMUNITY_DIR} ${PROJECT_BINARY_DIR} Darwin ${TD_VER_NUMBER})")
ENDIF ()

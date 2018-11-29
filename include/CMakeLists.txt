cmake_minimum_required(VERSION 2.8)
project(SEPLIB-base-include)

set(INCLUDES    
    sepcube.h	
   sep_old_external.h
	   sep_par.h	
prototypes.h  	   sep_pars_external.h	
	
sep3dc.h      sep_fortran.h	   		superset.h
sep3d.h       seplib.h		
      sep_main_external.h)

set(SCRIPTS sep_doc_it)

configure_file (
  "${PROJECT_SOURCE_DIR}/su.h.in"
  "${PROJECT_BINARY_DIR}/su.h"
  )

configure_file (
  "${PROJECT_SOURCE_DIR}/segy.h.in"
  "${PROJECT_BINARY_DIR}/segy.h"
  )

install(FILES ${INCLUDES} DESTINATION include)

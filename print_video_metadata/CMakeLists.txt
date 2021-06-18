add_executable (ffmpeg_entry "print_video_metadata.c")


target_include_directories(ffmpeg_entry PUBLIC ${FFMPEG_INCLUDE_DIRS})
target_link_libraries(ffmpeg_entry PUBLIC ${FFMPEG_LIBRARIES})

cmake_minimum_required (VERSION 3.8)

project ("ffmpeg_samples")

find_package(FFmpeg COMPONENTS AVCODEC AVFORMAT AVUTIL AVDEVICE REQUIRED) #add here the list of ffmpeg components required

add_subdirectory ("print_video_metadata")

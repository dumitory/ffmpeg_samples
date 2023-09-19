#include <stdio.h>
#include <libavformat/avformat.h>

void print_usage()
{
	printf("Usage:\n\t\t\tJust enter the path to the video file. Thank you.\n");
}

int main(int argc, char** argv)
{

	if (argc != 2)
	{
		print_usage();
		return 0;
	}

	const char* file_name = argv[1]; //file name 

	/*
		When using FFMPEG for development,
		AVFormatContext is a data structure that runs everywhere and many functions must use it as a parameter.
		This is the structure of the FFMPEG decapsulation function (flv, mp4, rmvb, avi).
	*/
	AVFormatContext* fmt_ctx = 0;

	/*
		 Each piece of metadata consists of two attributes: a key and a value.
	*/
	AVDictionaryEntry* tag = 0;

	/*
		The main things that gets done in file_open are:
		- Allocate memory for AVFormatContext.
		- Read the probe_size about of data from the file (input url)
		- Tries to guess the input file format, codec parameter for the input file. This is done by calling read_probe function pointer for each of the demuxer
		- Allocate the codec context, demuxed context, I/O context.
	*/
	int res = avformat_open_input(&fmt_ctx, file_name, NULL, NULL);

	if (res != 0)
	{
		return res;
	}
		

	/*
		Read packets of a media file to get stream information.
		This is useful for file formats with no headers such as MPEG.
		This function also computes the real framerate in case of MPEG-2 repeat frame mode.
		The logical file position is not changed by this function; examined packets may be buffered for later processing
	*/
	res = avformat_find_stream_info(fmt_ctx, NULL);
	
	if (res < 0)
	{
		avformat_close_input(&fmt_ctx);
		return res;
	}

	/*
		Print detailed information about the input or output format, such as duration, bitrate,
		streams, container, programs, metadata, side data, codec and time base.
	*/
	for (int i = 0; i < fmt_ctx->nb_streams; ++i)
	{	
		av_dump_format(fmt_ctx, i, file_name, 0);
	}

	avformat_close_input(&fmt_ctx);
	return 0;
}

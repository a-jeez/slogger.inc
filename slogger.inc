/*
		Simple record log with slogger
*	Author = https://github.com/phoenixx14/
*	Date = 28/02/2021
*/
/*
MIT License

Copyright (c) 2021 Phoenixx

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <a_samp>

#if defined slogger_inc
	#endinput
#endif
#define slogger_inc

stock Logs(filename[], input[]) {

	new	log_output[256], dateTime[2][3], File: fileHandle = fopen(filename, io_append);
	gettime(dateTime[0][0], dateTime[0][1], dateTime[0][2]);
	getdate(dateTime[1][0], dateTime[1][1], dateTime[1][2]);
	format(log_output, sizeof(log_output), "[%i/%i/%i - %i:%i:%i] %s\r\n", dateTime[1][0], dateTime[1][1], dateTime[1][2], dateTime[0][0], dateTime[0][1], dateTime[0][2], input);
	fwrite(fileHandle, log_output);
	return fclose(fileHandle);
}

stock LogsExists(filename[]) {
	return fexist(filename[]);
}

stock LogsRemove(filename[]) {
	if(!LogsExists(filename)) return false;
	fremove(filename[]);
}

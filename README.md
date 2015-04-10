# XboxAvi

## Summary

This will be C code for a program that will enlighten me about the contents and state of AVI files.

## History

Having no game console and just enough interest in having one, but not enough to pay full price, I bought one off a friend. This friend had gotten, through unfortunate circumstances, said Xbox locked out of Xbox Live, and (as far as I'm aware) the glory of the internet forever. I've searched online and have found and used files to manually update the audio/video codecs, but it still seems that it is unable to play video files that it should be able to. I have a set of videos that work wonderfully (AVIs), but others don't (MKVs). I'm able to convert the files that I know stand no chance of being recognized into files that should work, but the Xbox still complains that it can't play them.

## Description

So I have an Xbox that can play AVIs that I come across, but I can't seem to get it to play AVI files that I've created. I'm using ffmpeg to convert video files from formats that the Xbox won't even show in a list, but even when the converted AVI files have the same codecs as other AVI files that play, the Xbox will still give an error code.

I'm building this program mostly for me to understand what the difference in the files is, and then to use that information to correct the convesion process or to possibly patch the file itself. If I come up with something cool and useful this might get to be a bigger project, but if I just realize that ffmpeg needs another parameter or two then I'll probably end up deleting this repo and posting what I found in a forum somewhere.

## Resources Used

 * Installing ffmpeg on Ubuntu: http://wiki.razuna.com/display/ecp/FFmpeg+Installation+for+Ubuntu

 * visualization of AVI file: http://yaai.sourceforge.net/yaai/fileformat.html

 * AVI file specification: http://www.alexander-noe.com/video/documentation/avi.pdf

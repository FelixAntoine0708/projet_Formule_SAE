#!/usr/bin/python3

import RPi.GPIO as gpio

encodings = ['utf-8', 'latin-1']

for x in allmsg:
    for encoding in encodings:
        try:
            byte_array = bytes(x)
            result_string = byte_array.decode(encoding)
            decodemsg.append(result_string)
            break  
        except UnicodeDecodeError:
            continue  

    else:
        print("Unable to decode message:", x)    
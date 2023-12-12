### Find me in your files

This code searches for each 'FB499' sequence in hexadecimal digits, so you can find me in any file type!

---
#### Examples of matching
0000  61 62 **FB 49 9**0 00 68 69  00 0**F B4 99** 00 00 00 00 <br>
0010  00 64 63  00 00 **FB 49 9**c   00 30 78 00 f**F B4 99** 00  <br>

---

Since the program takes a file name in its arguments, you can search me for every file in a directory too.
```
find DIRECTORY -exec ./find.me '{}' \; | grep -oE '[0-9]+ times on .*' | sort -g
```
Or this to save every matching in `res.txt` 
```
find DIRECTORY -exec ./find.me '{}' \; | tee res.txt
grep -oE '[0-9]+ times on .*' res.txt | sort -g
```

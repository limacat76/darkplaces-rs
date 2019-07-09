### Diary

2/7 
* first step is retarget the solution to Windows 10 SDK: success
* second step is to build and play the game: success
* created the public github

3/7
* began writing this readme file
* began removing the #if 0 pieces of code

4/7
* started looking around in DP_FUNC_NORETURN, DP_FUNC_PRINTF and 
DP_FUNC_PURE. DP_FUNC_PRINTF seems a good place for starting to mess
with the codebase.
* began moving includes out of quakedef.h, it had sense in the 90's to
keep includes more centralized (in order to keep building times as low
as possible).

7/7
* The work on killing quakedef.h stopped momentarily, there are many
different things I can try to do right now still remaining on the C
side of the project...

9/7
* killed quakedef.h
* started working on mapping the various files
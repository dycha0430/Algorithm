{\rtf1\ansi\deff0\nouicompat{\fonttbl{\f0\fnil DotumChe;}{\f1\fnil\fcharset129 \'b8\'bc\'c0\'ba \'b0\'ed\'b5\'f1;}}
{\colortbl ;\red128\green128\blue128;\red0\green0\blue0;\red163\green21\blue21;\red0\green0\blue255;\red43\green145\blue175;\red0\green128\blue128;}
{\*\generator Riched20 10.0.22000}\viewkind4\uc1 
\pard\sa200\sl276\slmult1\cf1\f0\fs19\lang18 #include\cf2  \cf3 <iostream>\cf2\par
\cf1 #include\cf2  \cf3 <algorithm>\cf2\par
\par
\cf4 using\cf2  \cf4 namespace\cf2  std;\par
\cf4 typedef\cf2  \cf4 long\cf2  \cf4 long\cf2  \cf5 ll\cf2 ;\par
\par
\cf4 int\cf2  tetromino_x[19][4] = \{ \{0, 1, 2, 3\}, \{0, 0, 0, 0\}, \{0, 0, 1, 1\}, \{0, 1, 2, 2\}, \{1, 1, 1, 0\}, \{0, 0, 1, 2\}, \{1, 0, 0, 0\}, \{2, 2, 1, 0\}, \{0, 0, 0, 1\}, \{0, 0, 1, 2\}, \{0, 1, 1, 1\}, \{0, 1, 1, 2\}, \{1, 1, 0, 0\}, \{0, 1, 1, 2\}, \{0, 0, 1, 1\}, \{0, 0, 0, 1\}, \{0, 1, 1, 2\}, \{0, 1, 1, 2\}, \{1, 1, 1, 0\} \};\par
\cf4 int\cf2  tetromino_y[19][4] = \{ \{0, 0, 0, 0\}, \{0, 1, 2, 3\}, \{0, 1, 0, 1\}, \{0, 0, 0, 1\}, \{0, 1, 2, 2\}, \{0, 1, 1, 1\}, \{0, 0, 1, 2\}, \{0, 1, 1, 1\}, \{0, 1, 2, 2\}, \{1, 0, 0, 0\}, \{0, 0, 1, 2\}, \{0, 0, 1, 1\}, \{0, 1, 1, 2\}, \{1, 1, 0, 0\}, \{0, 1, 1, 2\}, \{0, 1, 2, 1\}, \{0, 0, 1, 0\}, \{1, 1, 0, 1\}, \{0, 1, 2, 1\} \};\par
\par
\par
\cf4 int\cf2  main(\cf4 int\cf2  \cf1 argc\cf2 , \cf4 char\cf2  \cf4 const\cf2 * \cf1 argv\cf2 [])\par
\{\par
\tab\cf4 int\cf2  N, M;\par
\tab\cf4 int\cf2 ** nums;\par
\tab cin \cf6 >>\cf2  N \cf6 >>\cf2  M;\par
\tab nums = \cf4 new\cf2  \cf4 int\cf2 * [N];\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 0; i < N; i++) \{\par
\tab\tab nums[i] = \cf4 new\cf2  \cf4 int\cf2 [M];\par
\tab\tab\cf4 for\cf2  (\cf4 int\cf2  j = 0; j < M; j++) cin \cf6 >>\cf2  nums[i][j];\par
\tab\}\tab\par
\par
\tab\cf4 int\cf2  answer = 0; \par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 0; i < N; i++) \{\par
\tab\tab\cf4 for\cf2  (\cf4 int\cf2  j = 0; j < M; j++) \{\par
\tab\tab\tab\cf4 for\cf2  (\cf4 int\cf2  k = 0; k < 19; k++) \{\par
\tab\tab\tab\tab\cf4 int\cf2  sum = 0;\par
\tab\tab\tab\tab\cf4 for\cf2  (\cf4 int\cf2  l = 0; l < 4; l++) \{\par
\tab\tab\tab\tab\tab\cf5 pair\cf2 <\cf4 int\cf2 , \cf4 int\cf2 > loc = \{ i + tetromino_x[k][l], j + tetromino_y[k][l] \};\par
\tab\tab\tab\tab\tab\cf4 if\cf2  (loc.first >= N || loc.second >= M) \{\par
\tab\tab\tab\tab\tab\tab sum = -1;\par
\tab\tab\tab\tab\tab\tab\cf4 break\cf2 ;\par
\tab\tab\tab\tab\tab\}\par
\tab\tab\tab\tab\tab\cf4 else\cf2  \{\par
\tab\tab\tab\tab\tab\tab sum += nums[loc.first][loc.second];\par
\tab\tab\tab\tab\tab\}\par
\tab\tab\tab\tab\}\par
\tab\tab\tab\tab answer = max(answer, sum);\par
\tab\tab\tab\}\par
\tab\tab\}\par
\tab\}\par
\par
\tab cout \cf6 <<\cf2  answer;\par
\par
\tab\cf4 return\cf2  0;\par
\}\par
\par
\cf0\f1\fs20\par
}
 
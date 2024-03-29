{\rtf1\ansi\deff0\nouicompat{\fonttbl{\f0\fnil DotumChe;}{\f1\fnil\fcharset129 \'b8\'bc\'c0\'ba \'b0\'ed\'b5\'f1;}}
{\colortbl ;\red128\green128\blue128;\red0\green0\blue0;\red163\green21\blue21;\red0\green0\blue255;\red43\green145\blue175;\red111\green0\blue138;\red0\green128\blue128;}
{\*\generator Riched20 10.0.22000}\viewkind4\uc1 
\pard\sa200\sl276\slmult1\cf1\f0\fs19\lang18 #include\cf2  \cf3 <iostream>\cf2\par
\cf1 #include\cf2  \cf3 <algorithm>\cf2\par
\par
\cf4 using\cf2  \cf4 namespace\cf2  std;\par
\cf4 typedef\cf2  \cf4 long\cf2  \cf4 long\cf2  \cf5 ll\cf2 ;\par
\par
\cf4 int\cf2  left_direction[4][2] = \{ \{0, -1\}, \{-1, 0\}, \{0, 1\}, \{1, 0\} \};\par
\cf4 int\cf2  back_direction[4][2] = \{ \{1, 0\}, \{0, -1\}, \{-1, 0\}, \{0, 1\} \};\par
\cf4 int\cf2  main(\cf4 int\cf2  \cf1 argc\cf2 , \cf4 char\cf2  \cf4 const\cf2 * \cf1 argv\cf2 [])\par
\{\par
\tab\cf5 ios\cf2 ::sync_with_stdio(\cf4 false\cf2 );\par
\tab cin.tie(\cf6 NULL\cf2 );\par
\tab cout.tie(\cf6 NULL\cf2 );\par
\par
\tab\cf4 int\cf2  N, M, r, c, d, answer = 0;\par
\tab\cf4 int\cf2  map[50][50];\par
\tab cin \cf7 >>\cf2  N \cf7 >>\cf2  M \cf7 >>\cf2  r \cf7 >>\cf2  c \cf7 >>\cf2  d;\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 0; i < N; i++) \{\par
\tab\tab\cf4 for\cf2  (\cf4 int\cf2  j = 0; j < M; j++) cin \cf7 >>\cf2  map[i][j];\par
\tab\}\par
\par
\tab\cf4 while\cf2  (\cf4 true\cf2 ) \{\par
\tab\tab\cf4 if\cf2  (map[r][c] == 0) \{\par
\tab\tab\tab map[r][c] = 2;\par
\tab\tab\tab answer++;\par
\tab\tab\}\par
\par
\tab\tab\cf4 bool\cf2  all_clean = \cf4 true\cf2 ;\par
\tab\tab\cf4 for\cf2  (\cf4 int\cf2  i = 0; i < 4; i++) \{\par
\tab\tab\tab\cf5 pair\cf2 <\cf4 int\cf2 , \cf4 int\cf2 > nextPos = \{ r + left_direction[i][0], c + left_direction[i][1] \};\par
\tab\tab\tab\cf4 if\cf2  (nextPos.first >= 0 && nextPos.second >= 0 && nextPos.first < N && nextPos.second < M && map[nextPos.first][nextPos.second] == 0) \{\par
\tab\tab\tab\tab all_clean = \cf4 false\cf2 ;\par
\tab\tab\tab\tab\cf4 break\cf2 ;\par
\tab\tab\tab\}\par
\tab\tab\}\par
\par
\tab\tab\cf4 if\cf2  (all_clean) \{\par
\tab\tab\tab\cf5 pair\cf2 <\cf4 int\cf2 , \cf4 int\cf2 > backPos = \{ r + back_direction[d][0], c + back_direction[d][1] \};\par
\tab\tab\tab\cf4 if\cf2  (backPos.first < 0 || backPos.second < 0 || backPos.first >= N || backPos.second >= M || map[backPos.first][backPos.second] == 1) \{\par
\tab\tab\tab\tab\cf4 break\cf2 ;\par
\tab\tab\tab\}\par
\tab\tab\tab\cf4 else\cf2  \{\par
\tab\tab\tab\tab r = backPos.first;\par
\tab\tab\tab\tab c = backPos.second;\par
\tab\tab\tab\tab\cf4 continue\cf2 ;\par
\tab\tab\tab\}\par
\tab\tab\}\par
\par
\tab\tab\cf5 pair\cf2 <\cf4 int\cf2 , \cf4 int\cf2 > nextPos = \{ r + left_direction[d][0], c + left_direction[d][1] \};\par
\tab\tab d--;\par
\tab\tab\cf4 if\cf2  (d < 0) d = 3;\par
\tab\tab\cf4 if\cf2  (nextPos.first < 0 || nextPos.second < 0 || nextPos.first >= N || nextPos.second >= M || map[nextPos.first][nextPos.second] != 0) \{\par
\tab\tab\tab\cf4 continue\cf2 ;\par
\tab\tab\}\par
\tab\tab\cf4 else\cf2  \{\par
\tab\tab\tab r = nextPos.first;\par
\tab\tab\tab c = nextPos.second;\par
\tab\tab\}\par
\tab\}\par
\par
\tab cout \cf7 <<\cf2  answer;\par
\par
\tab\cf4 return\cf2  0;\par
\}\par
\par
\cf0\f1\fs20\par
}
 
{\rtf1\ansi\deff0\nouicompat{\fonttbl{\f0\fnil DotumChe;}{\f1\fnil\fcharset129 \'b8\'bc\'c0\'ba \'b0\'ed\'b5\'f1;}}
{\colortbl ;\red128\green128\blue128;\red0\green0\blue0;\red163\green21\blue21;\red0\green0\blue255;\red43\green145\blue175;\red0\green128\blue128;}
{\*\generator Riched20 10.0.22000}\viewkind4\uc1 
\pard\sa200\sl276\slmult1\cf1\f0\fs19\lang18 #include\cf2  \cf3 <iostream>\cf2\par
\cf1 #include\cf2  \cf3 <algorithm>\cf2\par
\cf1 #include\cf2  \cf3 <vector>\cf2\par
\cf1 #include\cf2  \cf3 <math.h>\cf2\par
\par
\cf4 using\cf2  \cf4 namespace\cf2  std;\par
\cf4 typedef\cf2  \cf4 long\cf2  \cf4 long\cf2  \cf5 ll\cf2 ;\par
\par
\par
\cf4 int\cf2  main(\cf4 int\cf2  \cf1 argc\cf2 , \cf4 char\cf2  \cf4 const\cf2 * \cf1 argv\cf2 [])\par
\{\par
\tab\cf4 int\cf2  N, T;\par
\tab\cf4 int\cf2  K[101], S[101];\par
\par
\tab cin \cf6 >>\cf2  N \cf6 >>\cf2  T;\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 1; i <= N; i++) \{\par
\tab\tab cin \cf6 >>\cf2  K[i] \cf6 >>\cf2  S[i];\par
\tab\}\par
\tab\par
\tab\cf4 int\cf2 ** dp = \cf4 new\cf2  \cf4 int\cf2 * [N+1];\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 0; i <= N; i++) \{\par
\tab\tab dp[i] = \cf4 new\cf2  \cf4 int\cf2 [T+1];\par
\tab\tab\cf4 for\cf2  (\cf4 int\cf2  j = 0; j <= T; j++) dp[i][j] = 0;\par
\tab\}\par
\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 1; i <= N; i++) \{\par
\tab\tab\cf4 for\cf2  (\cf4 int\cf2  j = 1; j <= T; j++) \{\par
\tab\tab\tab\cf4 if\cf2  (j < K[i]) dp[i][j] = dp[i - 1][j];\par
\tab\tab\tab\cf4 else\cf2  dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - K[i]] + S[i]);\par
\tab\tab\}\par
\tab\}\par
\par
\tab cout \cf6 <<\cf2  dp[N][T] \cf6 <<\cf2  endl;\par
\par
\tab\cf4 return\cf2  0;\par
\}\par
\cf0\f1\fs20\par
}
 
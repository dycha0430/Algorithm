{\rtf1\ansi\deff0\nouicompat{\fonttbl{\f0\fnil DotumChe;}}
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
\tab\cf4 int\cf2  N, K;\par
\tab\cf4 int\cf2  nums[1000];\par
\tab\cf5 vector\cf2 <\cf4 int\cf2 >* dp = \cf4 new\cf2  \cf5 vector\cf2 <\cf4 int\cf2 >[51];\par
\tab cin \cf6 >>\cf2  N;\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 0; i < N; i++) \{\par
\tab\tab cin \cf6 >>\cf2  nums[i];\par
\tab\tab dp[1].push_back(nums[i]);\par
\tab\}\par
\par
\tab cin \cf6 >>\cf2  K;\par
\par
\tab\cf4 bool\cf2 * checked = \cf4 new\cf2  \cf4 bool\cf2 [50001];\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 0; i <= 50000; i++) checked[i] = \cf4 false\cf2 ;\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 0; i < dp[1].size(); i++) checked[dp[1]\cf6 [\cf2 i\cf6 ]\cf2 ] = \cf4 true\cf2 ;\par
\tab\par
\tab\cf4 int\cf2  cur_num = 0;\par
\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 2; i <= K; i++) \{\par
\tab\tab\cf4 for\cf2  (\cf4 int\cf2  j = 0; j < dp[i - 1].size(); j++) \{\par
\tab\tab\tab\cf4 for\cf2  (\cf4 int\cf2  k = 0; k < dp[1].size(); k++) \{\par
\tab\tab\tab\tab\cf4 int\cf2  num = dp[i - 1]\cf6 [\cf2 j\cf6 ]\cf2  + dp[1]\cf6 [\cf2 k\cf6 ]\cf2 ;\par
\tab\tab\tab\tab\cf4 if\cf2  (!checked[num]) \{\par
\tab\tab\tab\tab\tab dp[i].push_back(num);\par
\tab\tab\tab\tab\tab checked[num] = \cf4 true\cf2 ;\par
\tab\tab\tab\tab\}\par
\tab\tab\tab\}\par
\tab\tab\}\par
\tab\}\par
\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 1; i <= 50000; i++) \{\par
\tab\tab\cf4 if\cf2  (!checked[i]) \{\par
\tab\tab\tab\cf4 if\cf2  (i % 2) \{\par
\tab\tab\tab\tab cout \cf6 <<\cf2  \cf3 "jjaksoon win at "\cf2  \cf6 <<\cf2  i \cf6 <<\cf2  endl;\par
\tab\tab\tab\}\par
\tab\tab\tab\cf4 else\cf2  \{\par
\tab\tab\tab\tab cout \cf6 <<\cf2  \cf3 "holsoon win at "\cf2  \cf6 <<\cf2  i \cf6 <<\cf2  endl;\par
\tab\tab\tab\}\par
\par
\tab\tab\tab\cf4 break\cf2 ;\par
\tab\tab\}\par
\tab\}\par
\par
\tab\cf4 return\cf2  0;\par
\}\par
\par
}
 
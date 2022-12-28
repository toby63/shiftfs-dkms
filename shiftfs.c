<!DOCTYPE html>
<html lang='en'>
<head>
<title>shiftfs.c\fs - ~ubuntu-kernel/ubuntu/+source/linux/+git/lunar - [no description]</title>
<meta name='generator' content='cgit v1.1'/>
<meta name='robots' content='index, nofollow'/>
<link rel='stylesheet' type='text/css' href='/static/cgit-public.css'/>
<link rel='shortcut icon' href='/favicon.ico'/>
<link rel='alternate' title='Atom feed' href='http://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/atom/fs/shiftfs.c?h=lowlatency-next' type='application/atom+xml'/>
<link rel='vcs-git' href='git://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar' title='~ubuntu-kernel/ubuntu/+source/linux/+git/lunar Git repository'/>
<link rel='vcs-git' href='git+ssh://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar' title='~ubuntu-kernel/ubuntu/+source/linux/+git/lunar Git repository'/>
<link rel='vcs-git' href='https://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar' title='~ubuntu-kernel/ubuntu/+source/linux/+git/lunar Git repository'/>
</head>
<body>
<div id='cgit'><table id='header'>
<tr>
<td class='logo' rowspan='2'><a href='/'><img src='/static/launchpad-logo.png' alt='cgit logo'/></a></td>
<td class='main'><a href='/'>index</a> : <a title='~ubuntu-kernel/ubuntu/+source/linux/+git/lunar' href='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/'>~ubuntu-kernel/ubuntu/+source/linux/+git/lunar</a></td><td class='form'><form method='get'>
<select name='h' onchange='this.form.submit();'>
<option value='lowlatency'>lowlatency</option>
<option value='lowlatency-next' selected='selected'>lowlatency-next</option>
<option value='master'>master</option>
<option value='master-next'>master-next</option>
</select> <input type='submit' value='switch'/></form></td></tr>
<tr><td class='sub'>[no description]</td><td class='sub right'></td></tr></table>
<table class='tabs'><tr><td>
<a href='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/?h=lowlatency-next'>summary</a><a href='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/refs/?h=lowlatency-next'>refs</a><a href='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/log/fs/shiftfs.c?h=lowlatency-next'>log</a><a class='active' href='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/tree/fs/shiftfs.c?h=lowlatency-next'>tree</a><a href='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/commit/fs/shiftfs.c?h=lowlatency-next'>commit</a><a href='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/diff/fs/shiftfs.c?h=lowlatency-next'>diff</a></td><td class='form'><form class='right' method='get' action='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/log/fs/shiftfs.c'>
<input type='hidden' name='h' value='lowlatency-next'/><select name='qt'>
<option value='grep'>log msg</option>
<option value='author'>author</option>
<option value='committer'>committer</option>
<option value='range'>range</option>
</select>
<input class='txt' type='text' size='10' name='q' value=''/>
<input type='submit' value='search'/>
</form>
</td></tr></table>
<div class='path'>path: <a href='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/tree/?h=lowlatency-next'>root</a>/<a href='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/tree/fs?h=lowlatency-next'>fs</a>/<a href='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/tree/fs/shiftfs.c?h=lowlatency-next'>shiftfs.c</a></div><div class='content'>blob: 34f080ae0fec3b70c336c77cb5c3b42e0e6eba8d (<a href='/~ubuntu-kernel/ubuntu/+source/linux/+git/lunar/plain/fs/shiftfs.c?h=lowlatency-next'>plain</a>)
<table summary='blob content' class='blob'>
<tr><td class='linenumbers'><pre><a id='n1' href='#n1'>1</a>
<a id='n2' href='#n2'>2</a>
<a id='n3' href='#n3'>3</a>
<a id='n4' href='#n4'>4</a>
<a id='n5' href='#n5'>5</a>
<a id='n6' href='#n6'>6</a>
<a id='n7' href='#n7'>7</a>
<a id='n8' href='#n8'>8</a>
<a id='n9' href='#n9'>9</a>
<a id='n10' href='#n10'>10</a>
<a id='n11' href='#n11'>11</a>
<a id='n12' href='#n12'>12</a>
<a id='n13' href='#n13'>13</a>
<a id='n14' href='#n14'>14</a>
<a id='n15' href='#n15'>15</a>
<a id='n16' href='#n16'>16</a>
<a id='n17' href='#n17'>17</a>
<a id='n18' href='#n18'>18</a>
<a id='n19' href='#n19'>19</a>
<a id='n20' href='#n20'>20</a>
<a id='n21' href='#n21'>21</a>
<a id='n22' href='#n22'>22</a>
<a id='n23' href='#n23'>23</a>
<a id='n24' href='#n24'>24</a>
<a id='n25' href='#n25'>25</a>
<a id='n26' href='#n26'>26</a>
<a id='n27' href='#n27'>27</a>
<a id='n28' href='#n28'>28</a>
<a id='n29' href='#n29'>29</a>
<a id='n30' href='#n30'>30</a>
<a id='n31' href='#n31'>31</a>
<a id='n32' href='#n32'>32</a>
<a id='n33' href='#n33'>33</a>
<a id='n34' href='#n34'>34</a>
<a id='n35' href='#n35'>35</a>
<a id='n36' href='#n36'>36</a>
<a id='n37' href='#n37'>37</a>
<a id='n38' href='#n38'>38</a>
<a id='n39' href='#n39'>39</a>
<a id='n40' href='#n40'>40</a>
<a id='n41' href='#n41'>41</a>
<a id='n42' href='#n42'>42</a>
<a id='n43' href='#n43'>43</a>
<a id='n44' href='#n44'>44</a>
<a id='n45' href='#n45'>45</a>
<a id='n46' href='#n46'>46</a>
<a id='n47' href='#n47'>47</a>
<a id='n48' href='#n48'>48</a>
<a id='n49' href='#n49'>49</a>
<a id='n50' href='#n50'>50</a>
<a id='n51' href='#n51'>51</a>
<a id='n52' href='#n52'>52</a>
<a id='n53' href='#n53'>53</a>
<a id='n54' href='#n54'>54</a>
<a id='n55' href='#n55'>55</a>
<a id='n56' href='#n56'>56</a>
<a id='n57' href='#n57'>57</a>
<a id='n58' href='#n58'>58</a>
<a id='n59' href='#n59'>59</a>
<a id='n60' href='#n60'>60</a>
<a id='n61' href='#n61'>61</a>
<a id='n62' href='#n62'>62</a>
<a id='n63' href='#n63'>63</a>
<a id='n64' href='#n64'>64</a>
<a id='n65' href='#n65'>65</a>
<a id='n66' href='#n66'>66</a>
<a id='n67' href='#n67'>67</a>
<a id='n68' href='#n68'>68</a>
<a id='n69' href='#n69'>69</a>
<a id='n70' href='#n70'>70</a>
<a id='n71' href='#n71'>71</a>
<a id='n72' href='#n72'>72</a>
<a id='n73' href='#n73'>73</a>
<a id='n74' href='#n74'>74</a>
<a id='n75' href='#n75'>75</a>
<a id='n76' href='#n76'>76</a>
<a id='n77' href='#n77'>77</a>
<a id='n78' href='#n78'>78</a>
<a id='n79' href='#n79'>79</a>
<a id='n80' href='#n80'>80</a>
<a id='n81' href='#n81'>81</a>
<a id='n82' href='#n82'>82</a>
<a id='n83' href='#n83'>83</a>
<a id='n84' href='#n84'>84</a>
<a id='n85' href='#n85'>85</a>
<a id='n86' href='#n86'>86</a>
<a id='n87' href='#n87'>87</a>
<a id='n88' href='#n88'>88</a>
<a id='n89' href='#n89'>89</a>
<a id='n90' href='#n90'>90</a>
<a id='n91' href='#n91'>91</a>
<a id='n92' href='#n92'>92</a>
<a id='n93' href='#n93'>93</a>
<a id='n94' href='#n94'>94</a>
<a id='n95' href='#n95'>95</a>
<a id='n96' href='#n96'>96</a>
<a id='n97' href='#n97'>97</a>
<a id='n98' href='#n98'>98</a>
<a id='n99' href='#n99'>99</a>
<a id='n100' href='#n100'>100</a>
<a id='n101' href='#n101'>101</a>
<a id='n102' href='#n102'>102</a>
<a id='n103' href='#n103'>103</a>
<a id='n104' href='#n104'>104</a>
<a id='n105' href='#n105'>105</a>
<a id='n106' href='#n106'>106</a>
<a id='n107' href='#n107'>107</a>
<a id='n108' href='#n108'>108</a>
<a id='n109' href='#n109'>109</a>
<a id='n110' href='#n110'>110</a>
<a id='n111' href='#n111'>111</a>
<a id='n112' href='#n112'>112</a>
<a id='n113' href='#n113'>113</a>
<a id='n114' href='#n114'>114</a>
<a id='n115' href='#n115'>115</a>
<a id='n116' href='#n116'>116</a>
<a id='n117' href='#n117'>117</a>
<a id='n118' href='#n118'>118</a>
<a id='n119' href='#n119'>119</a>
<a id='n120' href='#n120'>120</a>
<a id='n121' href='#n121'>121</a>
<a id='n122' href='#n122'>122</a>
<a id='n123' href='#n123'>123</a>
<a id='n124' href='#n124'>124</a>
<a id='n125' href='#n125'>125</a>
<a id='n126' href='#n126'>126</a>
<a id='n127' href='#n127'>127</a>
<a id='n128' href='#n128'>128</a>
<a id='n129' href='#n129'>129</a>
<a id='n130' href='#n130'>130</a>
<a id='n131' href='#n131'>131</a>
<a id='n132' href='#n132'>132</a>
<a id='n133' href='#n133'>133</a>
<a id='n134' href='#n134'>134</a>
<a id='n135' href='#n135'>135</a>
<a id='n136' href='#n136'>136</a>
<a id='n137' href='#n137'>137</a>
<a id='n138' href='#n138'>138</a>
<a id='n139' href='#n139'>139</a>
<a id='n140' href='#n140'>140</a>
<a id='n141' href='#n141'>141</a>
<a id='n142' href='#n142'>142</a>
<a id='n143' href='#n143'>143</a>
<a id='n144' href='#n144'>144</a>
<a id='n145' href='#n145'>145</a>
<a id='n146' href='#n146'>146</a>
<a id='n147' href='#n147'>147</a>
<a id='n148' href='#n148'>148</a>
<a id='n149' href='#n149'>149</a>
<a id='n150' href='#n150'>150</a>
<a id='n151' href='#n151'>151</a>
<a id='n152' href='#n152'>152</a>
<a id='n153' href='#n153'>153</a>
<a id='n154' href='#n154'>154</a>
<a id='n155' href='#n155'>155</a>
<a id='n156' href='#n156'>156</a>
<a id='n157' href='#n157'>157</a>
<a id='n158' href='#n158'>158</a>
<a id='n159' href='#n159'>159</a>
<a id='n160' href='#n160'>160</a>
<a id='n161' href='#n161'>161</a>
<a id='n162' href='#n162'>162</a>
<a id='n163' href='#n163'>163</a>
<a id='n164' href='#n164'>164</a>
<a id='n165' href='#n165'>165</a>
<a id='n166' href='#n166'>166</a>
<a id='n167' href='#n167'>167</a>
<a id='n168' href='#n168'>168</a>
<a id='n169' href='#n169'>169</a>
<a id='n170' href='#n170'>170</a>
<a id='n171' href='#n171'>171</a>
<a id='n172' href='#n172'>172</a>
<a id='n173' href='#n173'>173</a>
<a id='n174' href='#n174'>174</a>
<a id='n175' href='#n175'>175</a>
<a id='n176' href='#n176'>176</a>
<a id='n177' href='#n177'>177</a>
<a id='n178' href='#n178'>178</a>
<a id='n179' href='#n179'>179</a>
<a id='n180' href='#n180'>180</a>
<a id='n181' href='#n181'>181</a>
<a id='n182' href='#n182'>182</a>
<a id='n183' href='#n183'>183</a>
<a id='n184' href='#n184'>184</a>
<a id='n185' href='#n185'>185</a>
<a id='n186' href='#n186'>186</a>
<a id='n187' href='#n187'>187</a>
<a id='n188' href='#n188'>188</a>
<a id='n189' href='#n189'>189</a>
<a id='n190' href='#n190'>190</a>
<a id='n191' href='#n191'>191</a>
<a id='n192' href='#n192'>192</a>
<a id='n193' href='#n193'>193</a>
<a id='n194' href='#n194'>194</a>
<a id='n195' href='#n195'>195</a>
<a id='n196' href='#n196'>196</a>
<a id='n197' href='#n197'>197</a>
<a id='n198' href='#n198'>198</a>
<a id='n199' href='#n199'>199</a>
<a id='n200' href='#n200'>200</a>
<a id='n201' href='#n201'>201</a>
<a id='n202' href='#n202'>202</a>
<a id='n203' href='#n203'>203</a>
<a id='n204' href='#n204'>204</a>
<a id='n205' href='#n205'>205</a>
<a id='n206' href='#n206'>206</a>
<a id='n207' href='#n207'>207</a>
<a id='n208' href='#n208'>208</a>
<a id='n209' href='#n209'>209</a>
<a id='n210' href='#n210'>210</a>
<a id='n211' href='#n211'>211</a>
<a id='n212' href='#n212'>212</a>
<a id='n213' href='#n213'>213</a>
<a id='n214' href='#n214'>214</a>
<a id='n215' href='#n215'>215</a>
<a id='n216' href='#n216'>216</a>
<a id='n217' href='#n217'>217</a>
<a id='n218' href='#n218'>218</a>
<a id='n219' href='#n219'>219</a>
<a id='n220' href='#n220'>220</a>
<a id='n221' href='#n221'>221</a>
<a id='n222' href='#n222'>222</a>
<a id='n223' href='#n223'>223</a>
<a id='n224' href='#n224'>224</a>
<a id='n225' href='#n225'>225</a>
<a id='n226' href='#n226'>226</a>
<a id='n227' href='#n227'>227</a>
<a id='n228' href='#n228'>228</a>
<a id='n229' href='#n229'>229</a>
<a id='n230' href='#n230'>230</a>
<a id='n231' href='#n231'>231</a>
<a id='n232' href='#n232'>232</a>
<a id='n233' href='#n233'>233</a>
<a id='n234' href='#n234'>234</a>
<a id='n235' href='#n235'>235</a>
<a id='n236' href='#n236'>236</a>
<a id='n237' href='#n237'>237</a>
<a id='n238' href='#n238'>238</a>
<a id='n239' href='#n239'>239</a>
<a id='n240' href='#n240'>240</a>
<a id='n241' href='#n241'>241</a>
<a id='n242' href='#n242'>242</a>
<a id='n243' href='#n243'>243</a>
<a id='n244' href='#n244'>244</a>
<a id='n245' href='#n245'>245</a>
<a id='n246' href='#n246'>246</a>
<a id='n247' href='#n247'>247</a>
<a id='n248' href='#n248'>248</a>
<a id='n249' href='#n249'>249</a>
<a id='n250' href='#n250'>250</a>
<a id='n251' href='#n251'>251</a>
<a id='n252' href='#n252'>252</a>
<a id='n253' href='#n253'>253</a>
<a id='n254' href='#n254'>254</a>
<a id='n255' href='#n255'>255</a>
<a id='n256' href='#n256'>256</a>
<a id='n257' href='#n257'>257</a>
<a id='n258' href='#n258'>258</a>
<a id='n259' href='#n259'>259</a>
<a id='n260' href='#n260'>260</a>
<a id='n261' href='#n261'>261</a>
<a id='n262' href='#n262'>262</a>
<a id='n263' href='#n263'>263</a>
<a id='n264' href='#n264'>264</a>
<a id='n265' href='#n265'>265</a>
<a id='n266' href='#n266'>266</a>
<a id='n267' href='#n267'>267</a>
<a id='n268' href='#n268'>268</a>
<a id='n269' href='#n269'>269</a>
<a id='n270' href='#n270'>270</a>
<a id='n271' href='#n271'>271</a>
<a id='n272' href='#n272'>272</a>
<a id='n273' href='#n273'>273</a>
<a id='n274' href='#n274'>274</a>
<a id='n275' href='#n275'>275</a>
<a id='n276' href='#n276'>276</a>
<a id='n277' href='#n277'>277</a>
<a id='n278' href='#n278'>278</a>
<a id='n279' href='#n279'>279</a>
<a id='n280' href='#n280'>280</a>
<a id='n281' href='#n281'>281</a>
<a id='n282' href='#n282'>282</a>
<a id='n283' href='#n283'>283</a>
<a id='n284' href='#n284'>284</a>
<a id='n285' href='#n285'>285</a>
<a id='n286' href='#n286'>286</a>
<a id='n287' href='#n287'>287</a>
<a id='n288' href='#n288'>288</a>
<a id='n289' href='#n289'>289</a>
<a id='n290' href='#n290'>290</a>
<a id='n291' href='#n291'>291</a>
<a id='n292' href='#n292'>292</a>
<a id='n293' href='#n293'>293</a>
<a id='n294' href='#n294'>294</a>
<a id='n295' href='#n295'>295</a>
<a id='n296' href='#n296'>296</a>
<a id='n297' href='#n297'>297</a>
<a id='n298' href='#n298'>298</a>
<a id='n299' href='#n299'>299</a>
<a id='n300' href='#n300'>300</a>
<a id='n301' href='#n301'>301</a>
<a id='n302' href='#n302'>302</a>
<a id='n303' href='#n303'>303</a>
<a id='n304' href='#n304'>304</a>
<a id='n305' href='#n305'>305</a>
<a id='n306' href='#n306'>306</a>
<a id='n307' href='#n307'>307</a>
<a id='n308' href='#n308'>308</a>
<a id='n309' href='#n309'>309</a>
<a id='n310' href='#n310'>310</a>
<a id='n311' href='#n311'>311</a>
<a id='n312' href='#n312'>312</a>
<a id='n313' href='#n313'>313</a>
<a id='n314' href='#n314'>314</a>
<a id='n315' href='#n315'>315</a>
<a id='n316' href='#n316'>316</a>
<a id='n317' href='#n317'>317</a>
<a id='n318' href='#n318'>318</a>
<a id='n319' href='#n319'>319</a>
<a id='n320' href='#n320'>320</a>
<a id='n321' href='#n321'>321</a>
<a id='n322' href='#n322'>322</a>
<a id='n323' href='#n323'>323</a>
<a id='n324' href='#n324'>324</a>
<a id='n325' href='#n325'>325</a>
<a id='n326' href='#n326'>326</a>
<a id='n327' href='#n327'>327</a>
<a id='n328' href='#n328'>328</a>
<a id='n329' href='#n329'>329</a>
<a id='n330' href='#n330'>330</a>
<a id='n331' href='#n331'>331</a>
<a id='n332' href='#n332'>332</a>
<a id='n333' href='#n333'>333</a>
<a id='n334' href='#n334'>334</a>
<a id='n335' href='#n335'>335</a>
<a id='n336' href='#n336'>336</a>
<a id='n337' href='#n337'>337</a>
<a id='n338' href='#n338'>338</a>
<a id='n339' href='#n339'>339</a>
<a id='n340' href='#n340'>340</a>
<a id='n341' href='#n341'>341</a>
<a id='n342' href='#n342'>342</a>
<a id='n343' href='#n343'>343</a>
<a id='n344' href='#n344'>344</a>
<a id='n345' href='#n345'>345</a>
<a id='n346' href='#n346'>346</a>
<a id='n347' href='#n347'>347</a>
<a id='n348' href='#n348'>348</a>
<a id='n349' href='#n349'>349</a>
<a id='n350' href='#n350'>350</a>
<a id='n351' href='#n351'>351</a>
<a id='n352' href='#n352'>352</a>
<a id='n353' href='#n353'>353</a>
<a id='n354' href='#n354'>354</a>
<a id='n355' href='#n355'>355</a>
<a id='n356' href='#n356'>356</a>
<a id='n357' href='#n357'>357</a>
<a id='n358' href='#n358'>358</a>
<a id='n359' href='#n359'>359</a>
<a id='n360' href='#n360'>360</a>
<a id='n361' href='#n361'>361</a>
<a id='n362' href='#n362'>362</a>
<a id='n363' href='#n363'>363</a>
<a id='n364' href='#n364'>364</a>
<a id='n365' href='#n365'>365</a>
<a id='n366' href='#n366'>366</a>
<a id='n367' href='#n367'>367</a>
<a id='n368' href='#n368'>368</a>
<a id='n369' href='#n369'>369</a>
<a id='n370' href='#n370'>370</a>
<a id='n371' href='#n371'>371</a>
<a id='n372' href='#n372'>372</a>
<a id='n373' href='#n373'>373</a>
<a id='n374' href='#n374'>374</a>
<a id='n375' href='#n375'>375</a>
<a id='n376' href='#n376'>376</a>
<a id='n377' href='#n377'>377</a>
<a id='n378' href='#n378'>378</a>
<a id='n379' href='#n379'>379</a>
<a id='n380' href='#n380'>380</a>
<a id='n381' href='#n381'>381</a>
<a id='n382' href='#n382'>382</a>
<a id='n383' href='#n383'>383</a>
<a id='n384' href='#n384'>384</a>
<a id='n385' href='#n385'>385</a>
<a id='n386' href='#n386'>386</a>
<a id='n387' href='#n387'>387</a>
<a id='n388' href='#n388'>388</a>
<a id='n389' href='#n389'>389</a>
<a id='n390' href='#n390'>390</a>
<a id='n391' href='#n391'>391</a>
<a id='n392' href='#n392'>392</a>
<a id='n393' href='#n393'>393</a>
<a id='n394' href='#n394'>394</a>
<a id='n395' href='#n395'>395</a>
<a id='n396' href='#n396'>396</a>
<a id='n397' href='#n397'>397</a>
<a id='n398' href='#n398'>398</a>
<a id='n399' href='#n399'>399</a>
<a id='n400' href='#n400'>400</a>
<a id='n401' href='#n401'>401</a>
<a id='n402' href='#n402'>402</a>
<a id='n403' href='#n403'>403</a>
<a id='n404' href='#n404'>404</a>
<a id='n405' href='#n405'>405</a>
<a id='n406' href='#n406'>406</a>
<a id='n407' href='#n407'>407</a>
<a id='n408' href='#n408'>408</a>
<a id='n409' href='#n409'>409</a>
<a id='n410' href='#n410'>410</a>
<a id='n411' href='#n411'>411</a>
<a id='n412' href='#n412'>412</a>
<a id='n413' href='#n413'>413</a>
<a id='n414' href='#n414'>414</a>
<a id='n415' href='#n415'>415</a>
<a id='n416' href='#n416'>416</a>
<a id='n417' href='#n417'>417</a>
<a id='n418' href='#n418'>418</a>
<a id='n419' href='#n419'>419</a>
<a id='n420' href='#n420'>420</a>
<a id='n421' href='#n421'>421</a>
<a id='n422' href='#n422'>422</a>
<a id='n423' href='#n423'>423</a>
<a id='n424' href='#n424'>424</a>
<a id='n425' href='#n425'>425</a>
<a id='n426' href='#n426'>426</a>
<a id='n427' href='#n427'>427</a>
<a id='n428' href='#n428'>428</a>
<a id='n429' href='#n429'>429</a>
<a id='n430' href='#n430'>430</a>
<a id='n431' href='#n431'>431</a>
<a id='n432' href='#n432'>432</a>
<a id='n433' href='#n433'>433</a>
<a id='n434' href='#n434'>434</a>
<a id='n435' href='#n435'>435</a>
<a id='n436' href='#n436'>436</a>
<a id='n437' href='#n437'>437</a>
<a id='n438' href='#n438'>438</a>
<a id='n439' href='#n439'>439</a>
<a id='n440' href='#n440'>440</a>
<a id='n441' href='#n441'>441</a>
<a id='n442' href='#n442'>442</a>
<a id='n443' href='#n443'>443</a>
<a id='n444' href='#n444'>444</a>
<a id='n445' href='#n445'>445</a>
<a id='n446' href='#n446'>446</a>
<a id='n447' href='#n447'>447</a>
<a id='n448' href='#n448'>448</a>
<a id='n449' href='#n449'>449</a>
<a id='n450' href='#n450'>450</a>
<a id='n451' href='#n451'>451</a>
<a id='n452' href='#n452'>452</a>
<a id='n453' href='#n453'>453</a>
<a id='n454' href='#n454'>454</a>
<a id='n455' href='#n455'>455</a>
<a id='n456' href='#n456'>456</a>
<a id='n457' href='#n457'>457</a>
<a id='n458' href='#n458'>458</a>
<a id='n459' href='#n459'>459</a>
<a id='n460' href='#n460'>460</a>
<a id='n461' href='#n461'>461</a>
<a id='n462' href='#n462'>462</a>
<a id='n463' href='#n463'>463</a>
<a id='n464' href='#n464'>464</a>
<a id='n465' href='#n465'>465</a>
<a id='n466' href='#n466'>466</a>
<a id='n467' href='#n467'>467</a>
<a id='n468' href='#n468'>468</a>
<a id='n469' href='#n469'>469</a>
<a id='n470' href='#n470'>470</a>
<a id='n471' href='#n471'>471</a>
<a id='n472' href='#n472'>472</a>
<a id='n473' href='#n473'>473</a>
<a id='n474' href='#n474'>474</a>
<a id='n475' href='#n475'>475</a>
<a id='n476' href='#n476'>476</a>
<a id='n477' href='#n477'>477</a>
<a id='n478' href='#n478'>478</a>
<a id='n479' href='#n479'>479</a>
<a id='n480' href='#n480'>480</a>
<a id='n481' href='#n481'>481</a>
<a id='n482' href='#n482'>482</a>
<a id='n483' href='#n483'>483</a>
<a id='n484' href='#n484'>484</a>
<a id='n485' href='#n485'>485</a>
<a id='n486' href='#n486'>486</a>
<a id='n487' href='#n487'>487</a>
<a id='n488' href='#n488'>488</a>
<a id='n489' href='#n489'>489</a>
<a id='n490' href='#n490'>490</a>
<a id='n491' href='#n491'>491</a>
<a id='n492' href='#n492'>492</a>
<a id='n493' href='#n493'>493</a>
<a id='n494' href='#n494'>494</a>
<a id='n495' href='#n495'>495</a>
<a id='n496' href='#n496'>496</a>
<a id='n497' href='#n497'>497</a>
<a id='n498' href='#n498'>498</a>
<a id='n499' href='#n499'>499</a>
<a id='n500' href='#n500'>500</a>
<a id='n501' href='#n501'>501</a>
<a id='n502' href='#n502'>502</a>
<a id='n503' href='#n503'>503</a>
<a id='n504' href='#n504'>504</a>
<a id='n505' href='#n505'>505</a>
<a id='n506' href='#n506'>506</a>
<a id='n507' href='#n507'>507</a>
<a id='n508' href='#n508'>508</a>
<a id='n509' href='#n509'>509</a>
<a id='n510' href='#n510'>510</a>
<a id='n511' href='#n511'>511</a>
<a id='n512' href='#n512'>512</a>
<a id='n513' href='#n513'>513</a>
<a id='n514' href='#n514'>514</a>
<a id='n515' href='#n515'>515</a>
<a id='n516' href='#n516'>516</a>
<a id='n517' href='#n517'>517</a>
<a id='n518' href='#n518'>518</a>
<a id='n519' href='#n519'>519</a>
<a id='n520' href='#n520'>520</a>
<a id='n521' href='#n521'>521</a>
<a id='n522' href='#n522'>522</a>
<a id='n523' href='#n523'>523</a>
<a id='n524' href='#n524'>524</a>
<a id='n525' href='#n525'>525</a>
<a id='n526' href='#n526'>526</a>
<a id='n527' href='#n527'>527</a>
<a id='n528' href='#n528'>528</a>
<a id='n529' href='#n529'>529</a>
<a id='n530' href='#n530'>530</a>
<a id='n531' href='#n531'>531</a>
<a id='n532' href='#n532'>532</a>
<a id='n533' href='#n533'>533</a>
<a id='n534' href='#n534'>534</a>
<a id='n535' href='#n535'>535</a>
<a id='n536' href='#n536'>536</a>
<a id='n537' href='#n537'>537</a>
<a id='n538' href='#n538'>538</a>
<a id='n539' href='#n539'>539</a>
<a id='n540' href='#n540'>540</a>
<a id='n541' href='#n541'>541</a>
<a id='n542' href='#n542'>542</a>
<a id='n543' href='#n543'>543</a>
<a id='n544' href='#n544'>544</a>
<a id='n545' href='#n545'>545</a>
<a id='n546' href='#n546'>546</a>
<a id='n547' href='#n547'>547</a>
<a id='n548' href='#n548'>548</a>
<a id='n549' href='#n549'>549</a>
<a id='n550' href='#n550'>550</a>
<a id='n551' href='#n551'>551</a>
<a id='n552' href='#n552'>552</a>
<a id='n553' href='#n553'>553</a>
<a id='n554' href='#n554'>554</a>
<a id='n555' href='#n555'>555</a>
<a id='n556' href='#n556'>556</a>
<a id='n557' href='#n557'>557</a>
<a id='n558' href='#n558'>558</a>
<a id='n559' href='#n559'>559</a>
<a id='n560' href='#n560'>560</a>
<a id='n561' href='#n561'>561</a>
<a id='n562' href='#n562'>562</a>
<a id='n563' href='#n563'>563</a>
<a id='n564' href='#n564'>564</a>
<a id='n565' href='#n565'>565</a>
<a id='n566' href='#n566'>566</a>
<a id='n567' href='#n567'>567</a>
<a id='n568' href='#n568'>568</a>
<a id='n569' href='#n569'>569</a>
<a id='n570' href='#n570'>570</a>
<a id='n571' href='#n571'>571</a>
<a id='n572' href='#n572'>572</a>
<a id='n573' href='#n573'>573</a>
<a id='n574' href='#n574'>574</a>
<a id='n575' href='#n575'>575</a>
<a id='n576' href='#n576'>576</a>
<a id='n577' href='#n577'>577</a>
<a id='n578' href='#n578'>578</a>
<a id='n579' href='#n579'>579</a>
<a id='n580' href='#n580'>580</a>
<a id='n581' href='#n581'>581</a>
<a id='n582' href='#n582'>582</a>
<a id='n583' href='#n583'>583</a>
<a id='n584' href='#n584'>584</a>
<a id='n585' href='#n585'>585</a>
<a id='n586' href='#n586'>586</a>
<a id='n587' href='#n587'>587</a>
<a id='n588' href='#n588'>588</a>
<a id='n589' href='#n589'>589</a>
<a id='n590' href='#n590'>590</a>
<a id='n591' href='#n591'>591</a>
<a id='n592' href='#n592'>592</a>
<a id='n593' href='#n593'>593</a>
<a id='n594' href='#n594'>594</a>
<a id='n595' href='#n595'>595</a>
<a id='n596' href='#n596'>596</a>
<a id='n597' href='#n597'>597</a>
<a id='n598' href='#n598'>598</a>
<a id='n599' href='#n599'>599</a>
<a id='n600' href='#n600'>600</a>
<a id='n601' href='#n601'>601</a>
<a id='n602' href='#n602'>602</a>
<a id='n603' href='#n603'>603</a>
<a id='n604' href='#n604'>604</a>
<a id='n605' href='#n605'>605</a>
<a id='n606' href='#n606'>606</a>
<a id='n607' href='#n607'>607</a>
<a id='n608' href='#n608'>608</a>
<a id='n609' href='#n609'>609</a>
<a id='n610' href='#n610'>610</a>
<a id='n611' href='#n611'>611</a>
<a id='n612' href='#n612'>612</a>
<a id='n613' href='#n613'>613</a>
<a id='n614' href='#n614'>614</a>
<a id='n615' href='#n615'>615</a>
<a id='n616' href='#n616'>616</a>
<a id='n617' href='#n617'>617</a>
<a id='n618' href='#n618'>618</a>
<a id='n619' href='#n619'>619</a>
<a id='n620' href='#n620'>620</a>
<a id='n621' href='#n621'>621</a>
<a id='n622' href='#n622'>622</a>
<a id='n623' href='#n623'>623</a>
<a id='n624' href='#n624'>624</a>
<a id='n625' href='#n625'>625</a>
<a id='n626' href='#n626'>626</a>
<a id='n627' href='#n627'>627</a>
<a id='n628' href='#n628'>628</a>
<a id='n629' href='#n629'>629</a>
<a id='n630' href='#n630'>630</a>
<a id='n631' href='#n631'>631</a>
<a id='n632' href='#n632'>632</a>
<a id='n633' href='#n633'>633</a>
<a id='n634' href='#n634'>634</a>
<a id='n635' href='#n635'>635</a>
<a id='n636' href='#n636'>636</a>
<a id='n637' href='#n637'>637</a>
<a id='n638' href='#n638'>638</a>
<a id='n639' href='#n639'>639</a>
<a id='n640' href='#n640'>640</a>
<a id='n641' href='#n641'>641</a>
<a id='n642' href='#n642'>642</a>
<a id='n643' href='#n643'>643</a>
<a id='n644' href='#n644'>644</a>
<a id='n645' href='#n645'>645</a>
<a id='n646' href='#n646'>646</a>
<a id='n647' href='#n647'>647</a>
<a id='n648' href='#n648'>648</a>
<a id='n649' href='#n649'>649</a>
<a id='n650' href='#n650'>650</a>
<a id='n651' href='#n651'>651</a>
<a id='n652' href='#n652'>652</a>
<a id='n653' href='#n653'>653</a>
<a id='n654' href='#n654'>654</a>
<a id='n655' href='#n655'>655</a>
<a id='n656' href='#n656'>656</a>
<a id='n657' href='#n657'>657</a>
<a id='n658' href='#n658'>658</a>
<a id='n659' href='#n659'>659</a>
<a id='n660' href='#n660'>660</a>
<a id='n661' href='#n661'>661</a>
<a id='n662' href='#n662'>662</a>
<a id='n663' href='#n663'>663</a>
<a id='n664' href='#n664'>664</a>
<a id='n665' href='#n665'>665</a>
<a id='n666' href='#n666'>666</a>
<a id='n667' href='#n667'>667</a>
<a id='n668' href='#n668'>668</a>
<a id='n669' href='#n669'>669</a>
<a id='n670' href='#n670'>670</a>
<a id='n671' href='#n671'>671</a>
<a id='n672' href='#n672'>672</a>
<a id='n673' href='#n673'>673</a>
<a id='n674' href='#n674'>674</a>
<a id='n675' href='#n675'>675</a>
<a id='n676' href='#n676'>676</a>
<a id='n677' href='#n677'>677</a>
<a id='n678' href='#n678'>678</a>
<a id='n679' href='#n679'>679</a>
<a id='n680' href='#n680'>680</a>
<a id='n681' href='#n681'>681</a>
<a id='n682' href='#n682'>682</a>
<a id='n683' href='#n683'>683</a>
<a id='n684' href='#n684'>684</a>
<a id='n685' href='#n685'>685</a>
<a id='n686' href='#n686'>686</a>
<a id='n687' href='#n687'>687</a>
<a id='n688' href='#n688'>688</a>
<a id='n689' href='#n689'>689</a>
<a id='n690' href='#n690'>690</a>
<a id='n691' href='#n691'>691</a>
<a id='n692' href='#n692'>692</a>
<a id='n693' href='#n693'>693</a>
<a id='n694' href='#n694'>694</a>
<a id='n695' href='#n695'>695</a>
<a id='n696' href='#n696'>696</a>
<a id='n697' href='#n697'>697</a>
<a id='n698' href='#n698'>698</a>
<a id='n699' href='#n699'>699</a>
<a id='n700' href='#n700'>700</a>
<a id='n701' href='#n701'>701</a>
<a id='n702' href='#n702'>702</a>
<a id='n703' href='#n703'>703</a>
<a id='n704' href='#n704'>704</a>
<a id='n705' href='#n705'>705</a>
<a id='n706' href='#n706'>706</a>
<a id='n707' href='#n707'>707</a>
<a id='n708' href='#n708'>708</a>
<a id='n709' href='#n709'>709</a>
<a id='n710' href='#n710'>710</a>
<a id='n711' href='#n711'>711</a>
<a id='n712' href='#n712'>712</a>
<a id='n713' href='#n713'>713</a>
<a id='n714' href='#n714'>714</a>
<a id='n715' href='#n715'>715</a>
<a id='n716' href='#n716'>716</a>
<a id='n717' href='#n717'>717</a>
<a id='n718' href='#n718'>718</a>
<a id='n719' href='#n719'>719</a>
<a id='n720' href='#n720'>720</a>
<a id='n721' href='#n721'>721</a>
<a id='n722' href='#n722'>722</a>
<a id='n723' href='#n723'>723</a>
<a id='n724' href='#n724'>724</a>
<a id='n725' href='#n725'>725</a>
<a id='n726' href='#n726'>726</a>
<a id='n727' href='#n727'>727</a>
<a id='n728' href='#n728'>728</a>
<a id='n729' href='#n729'>729</a>
<a id='n730' href='#n730'>730</a>
<a id='n731' href='#n731'>731</a>
<a id='n732' href='#n732'>732</a>
<a id='n733' href='#n733'>733</a>
<a id='n734' href='#n734'>734</a>
<a id='n735' href='#n735'>735</a>
<a id='n736' href='#n736'>736</a>
<a id='n737' href='#n737'>737</a>
<a id='n738' href='#n738'>738</a>
<a id='n739' href='#n739'>739</a>
<a id='n740' href='#n740'>740</a>
<a id='n741' href='#n741'>741</a>
<a id='n742' href='#n742'>742</a>
<a id='n743' href='#n743'>743</a>
<a id='n744' href='#n744'>744</a>
<a id='n745' href='#n745'>745</a>
<a id='n746' href='#n746'>746</a>
<a id='n747' href='#n747'>747</a>
<a id='n748' href='#n748'>748</a>
<a id='n749' href='#n749'>749</a>
<a id='n750' href='#n750'>750</a>
<a id='n751' href='#n751'>751</a>
<a id='n752' href='#n752'>752</a>
<a id='n753' href='#n753'>753</a>
<a id='n754' href='#n754'>754</a>
<a id='n755' href='#n755'>755</a>
<a id='n756' href='#n756'>756</a>
<a id='n757' href='#n757'>757</a>
<a id='n758' href='#n758'>758</a>
<a id='n759' href='#n759'>759</a>
<a id='n760' href='#n760'>760</a>
<a id='n761' href='#n761'>761</a>
<a id='n762' href='#n762'>762</a>
<a id='n763' href='#n763'>763</a>
<a id='n764' href='#n764'>764</a>
<a id='n765' href='#n765'>765</a>
<a id='n766' href='#n766'>766</a>
<a id='n767' href='#n767'>767</a>
<a id='n768' href='#n768'>768</a>
<a id='n769' href='#n769'>769</a>
<a id='n770' href='#n770'>770</a>
<a id='n771' href='#n771'>771</a>
<a id='n772' href='#n772'>772</a>
<a id='n773' href='#n773'>773</a>
<a id='n774' href='#n774'>774</a>
<a id='n775' href='#n775'>775</a>
<a id='n776' href='#n776'>776</a>
<a id='n777' href='#n777'>777</a>
<a id='n778' href='#n778'>778</a>
<a id='n779' href='#n779'>779</a>
<a id='n780' href='#n780'>780</a>
<a id='n781' href='#n781'>781</a>
<a id='n782' href='#n782'>782</a>
<a id='n783' href='#n783'>783</a>
<a id='n784' href='#n784'>784</a>
<a id='n785' href='#n785'>785</a>
<a id='n786' href='#n786'>786</a>
<a id='n787' href='#n787'>787</a>
<a id='n788' href='#n788'>788</a>
<a id='n789' href='#n789'>789</a>
<a id='n790' href='#n790'>790</a>
<a id='n791' href='#n791'>791</a>
<a id='n792' href='#n792'>792</a>
<a id='n793' href='#n793'>793</a>
<a id='n794' href='#n794'>794</a>
<a id='n795' href='#n795'>795</a>
<a id='n796' href='#n796'>796</a>
<a id='n797' href='#n797'>797</a>
<a id='n798' href='#n798'>798</a>
<a id='n799' href='#n799'>799</a>
<a id='n800' href='#n800'>800</a>
<a id='n801' href='#n801'>801</a>
<a id='n802' href='#n802'>802</a>
<a id='n803' href='#n803'>803</a>
<a id='n804' href='#n804'>804</a>
<a id='n805' href='#n805'>805</a>
<a id='n806' href='#n806'>806</a>
<a id='n807' href='#n807'>807</a>
<a id='n808' href='#n808'>808</a>
<a id='n809' href='#n809'>809</a>
<a id='n810' href='#n810'>810</a>
<a id='n811' href='#n811'>811</a>
<a id='n812' href='#n812'>812</a>
<a id='n813' href='#n813'>813</a>
<a id='n814' href='#n814'>814</a>
<a id='n815' href='#n815'>815</a>
<a id='n816' href='#n816'>816</a>
<a id='n817' href='#n817'>817</a>
<a id='n818' href='#n818'>818</a>
<a id='n819' href='#n819'>819</a>
<a id='n820' href='#n820'>820</a>
<a id='n821' href='#n821'>821</a>
<a id='n822' href='#n822'>822</a>
<a id='n823' href='#n823'>823</a>
<a id='n824' href='#n824'>824</a>
<a id='n825' href='#n825'>825</a>
<a id='n826' href='#n826'>826</a>
<a id='n827' href='#n827'>827</a>
<a id='n828' href='#n828'>828</a>
<a id='n829' href='#n829'>829</a>
<a id='n830' href='#n830'>830</a>
<a id='n831' href='#n831'>831</a>
<a id='n832' href='#n832'>832</a>
<a id='n833' href='#n833'>833</a>
<a id='n834' href='#n834'>834</a>
<a id='n835' href='#n835'>835</a>
<a id='n836' href='#n836'>836</a>
<a id='n837' href='#n837'>837</a>
<a id='n838' href='#n838'>838</a>
<a id='n839' href='#n839'>839</a>
<a id='n840' href='#n840'>840</a>
<a id='n841' href='#n841'>841</a>
<a id='n842' href='#n842'>842</a>
<a id='n843' href='#n843'>843</a>
<a id='n844' href='#n844'>844</a>
<a id='n845' href='#n845'>845</a>
<a id='n846' href='#n846'>846</a>
<a id='n847' href='#n847'>847</a>
<a id='n848' href='#n848'>848</a>
<a id='n849' href='#n849'>849</a>
<a id='n850' href='#n850'>850</a>
<a id='n851' href='#n851'>851</a>
<a id='n852' href='#n852'>852</a>
<a id='n853' href='#n853'>853</a>
<a id='n854' href='#n854'>854</a>
<a id='n855' href='#n855'>855</a>
<a id='n856' href='#n856'>856</a>
<a id='n857' href='#n857'>857</a>
<a id='n858' href='#n858'>858</a>
<a id='n859' href='#n859'>859</a>
<a id='n860' href='#n860'>860</a>
<a id='n861' href='#n861'>861</a>
<a id='n862' href='#n862'>862</a>
<a id='n863' href='#n863'>863</a>
<a id='n864' href='#n864'>864</a>
<a id='n865' href='#n865'>865</a>
<a id='n866' href='#n866'>866</a>
<a id='n867' href='#n867'>867</a>
<a id='n868' href='#n868'>868</a>
<a id='n869' href='#n869'>869</a>
<a id='n870' href='#n870'>870</a>
<a id='n871' href='#n871'>871</a>
<a id='n872' href='#n872'>872</a>
<a id='n873' href='#n873'>873</a>
<a id='n874' href='#n874'>874</a>
<a id='n875' href='#n875'>875</a>
<a id='n876' href='#n876'>876</a>
<a id='n877' href='#n877'>877</a>
<a id='n878' href='#n878'>878</a>
<a id='n879' href='#n879'>879</a>
<a id='n880' href='#n880'>880</a>
<a id='n881' href='#n881'>881</a>
<a id='n882' href='#n882'>882</a>
<a id='n883' href='#n883'>883</a>
<a id='n884' href='#n884'>884</a>
<a id='n885' href='#n885'>885</a>
<a id='n886' href='#n886'>886</a>
<a id='n887' href='#n887'>887</a>
<a id='n888' href='#n888'>888</a>
<a id='n889' href='#n889'>889</a>
<a id='n890' href='#n890'>890</a>
<a id='n891' href='#n891'>891</a>
<a id='n892' href='#n892'>892</a>
<a id='n893' href='#n893'>893</a>
<a id='n894' href='#n894'>894</a>
<a id='n895' href='#n895'>895</a>
<a id='n896' href='#n896'>896</a>
<a id='n897' href='#n897'>897</a>
<a id='n898' href='#n898'>898</a>
<a id='n899' href='#n899'>899</a>
<a id='n900' href='#n900'>900</a>
<a id='n901' href='#n901'>901</a>
<a id='n902' href='#n902'>902</a>
<a id='n903' href='#n903'>903</a>
<a id='n904' href='#n904'>904</a>
<a id='n905' href='#n905'>905</a>
<a id='n906' href='#n906'>906</a>
<a id='n907' href='#n907'>907</a>
<a id='n908' href='#n908'>908</a>
<a id='n909' href='#n909'>909</a>
<a id='n910' href='#n910'>910</a>
<a id='n911' href='#n911'>911</a>
<a id='n912' href='#n912'>912</a>
<a id='n913' href='#n913'>913</a>
<a id='n914' href='#n914'>914</a>
<a id='n915' href='#n915'>915</a>
<a id='n916' href='#n916'>916</a>
<a id='n917' href='#n917'>917</a>
<a id='n918' href='#n918'>918</a>
<a id='n919' href='#n919'>919</a>
<a id='n920' href='#n920'>920</a>
<a id='n921' href='#n921'>921</a>
<a id='n922' href='#n922'>922</a>
<a id='n923' href='#n923'>923</a>
<a id='n924' href='#n924'>924</a>
<a id='n925' href='#n925'>925</a>
<a id='n926' href='#n926'>926</a>
<a id='n927' href='#n927'>927</a>
<a id='n928' href='#n928'>928</a>
<a id='n929' href='#n929'>929</a>
<a id='n930' href='#n930'>930</a>
<a id='n931' href='#n931'>931</a>
<a id='n932' href='#n932'>932</a>
<a id='n933' href='#n933'>933</a>
<a id='n934' href='#n934'>934</a>
<a id='n935' href='#n935'>935</a>
<a id='n936' href='#n936'>936</a>
<a id='n937' href='#n937'>937</a>
<a id='n938' href='#n938'>938</a>
<a id='n939' href='#n939'>939</a>
<a id='n940' href='#n940'>940</a>
<a id='n941' href='#n941'>941</a>
<a id='n942' href='#n942'>942</a>
<a id='n943' href='#n943'>943</a>
<a id='n944' href='#n944'>944</a>
<a id='n945' href='#n945'>945</a>
<a id='n946' href='#n946'>946</a>
<a id='n947' href='#n947'>947</a>
<a id='n948' href='#n948'>948</a>
<a id='n949' href='#n949'>949</a>
<a id='n950' href='#n950'>950</a>
<a id='n951' href='#n951'>951</a>
<a id='n952' href='#n952'>952</a>
<a id='n953' href='#n953'>953</a>
<a id='n954' href='#n954'>954</a>
<a id='n955' href='#n955'>955</a>
<a id='n956' href='#n956'>956</a>
<a id='n957' href='#n957'>957</a>
<a id='n958' href='#n958'>958</a>
<a id='n959' href='#n959'>959</a>
<a id='n960' href='#n960'>960</a>
<a id='n961' href='#n961'>961</a>
<a id='n962' href='#n962'>962</a>
<a id='n963' href='#n963'>963</a>
<a id='n964' href='#n964'>964</a>
<a id='n965' href='#n965'>965</a>
<a id='n966' href='#n966'>966</a>
<a id='n967' href='#n967'>967</a>
<a id='n968' href='#n968'>968</a>
<a id='n969' href='#n969'>969</a>
<a id='n970' href='#n970'>970</a>
<a id='n971' href='#n971'>971</a>
<a id='n972' href='#n972'>972</a>
<a id='n973' href='#n973'>973</a>
<a id='n974' href='#n974'>974</a>
<a id='n975' href='#n975'>975</a>
<a id='n976' href='#n976'>976</a>
<a id='n977' href='#n977'>977</a>
<a id='n978' href='#n978'>978</a>
<a id='n979' href='#n979'>979</a>
<a id='n980' href='#n980'>980</a>
<a id='n981' href='#n981'>981</a>
<a id='n982' href='#n982'>982</a>
<a id='n983' href='#n983'>983</a>
<a id='n984' href='#n984'>984</a>
<a id='n985' href='#n985'>985</a>
<a id='n986' href='#n986'>986</a>
<a id='n987' href='#n987'>987</a>
<a id='n988' href='#n988'>988</a>
<a id='n989' href='#n989'>989</a>
<a id='n990' href='#n990'>990</a>
<a id='n991' href='#n991'>991</a>
<a id='n992' href='#n992'>992</a>
<a id='n993' href='#n993'>993</a>
<a id='n994' href='#n994'>994</a>
<a id='n995' href='#n995'>995</a>
<a id='n996' href='#n996'>996</a>
<a id='n997' href='#n997'>997</a>
<a id='n998' href='#n998'>998</a>
<a id='n999' href='#n999'>999</a>
<a id='n1000' href='#n1000'>1000</a>
<a id='n1001' href='#n1001'>1001</a>
<a id='n1002' href='#n1002'>1002</a>
<a id='n1003' href='#n1003'>1003</a>
<a id='n1004' href='#n1004'>1004</a>
<a id='n1005' href='#n1005'>1005</a>
<a id='n1006' href='#n1006'>1006</a>
<a id='n1007' href='#n1007'>1007</a>
<a id='n1008' href='#n1008'>1008</a>
<a id='n1009' href='#n1009'>1009</a>
<a id='n1010' href='#n1010'>1010</a>
<a id='n1011' href='#n1011'>1011</a>
<a id='n1012' href='#n1012'>1012</a>
<a id='n1013' href='#n1013'>1013</a>
<a id='n1014' href='#n1014'>1014</a>
<a id='n1015' href='#n1015'>1015</a>
<a id='n1016' href='#n1016'>1016</a>
<a id='n1017' href='#n1017'>1017</a>
<a id='n1018' href='#n1018'>1018</a>
<a id='n1019' href='#n1019'>1019</a>
<a id='n1020' href='#n1020'>1020</a>
<a id='n1021' href='#n1021'>1021</a>
<a id='n1022' href='#n1022'>1022</a>
<a id='n1023' href='#n1023'>1023</a>
<a id='n1024' href='#n1024'>1024</a>
<a id='n1025' href='#n1025'>1025</a>
<a id='n1026' href='#n1026'>1026</a>
<a id='n1027' href='#n1027'>1027</a>
<a id='n1028' href='#n1028'>1028</a>
<a id='n1029' href='#n1029'>1029</a>
<a id='n1030' href='#n1030'>1030</a>
<a id='n1031' href='#n1031'>1031</a>
<a id='n1032' href='#n1032'>1032</a>
<a id='n1033' href='#n1033'>1033</a>
<a id='n1034' href='#n1034'>1034</a>
<a id='n1035' href='#n1035'>1035</a>
<a id='n1036' href='#n1036'>1036</a>
<a id='n1037' href='#n1037'>1037</a>
<a id='n1038' href='#n1038'>1038</a>
<a id='n1039' href='#n1039'>1039</a>
<a id='n1040' href='#n1040'>1040</a>
<a id='n1041' href='#n1041'>1041</a>
<a id='n1042' href='#n1042'>1042</a>
<a id='n1043' href='#n1043'>1043</a>
<a id='n1044' href='#n1044'>1044</a>
<a id='n1045' href='#n1045'>1045</a>
<a id='n1046' href='#n1046'>1046</a>
<a id='n1047' href='#n1047'>1047</a>
<a id='n1048' href='#n1048'>1048</a>
<a id='n1049' href='#n1049'>1049</a>
<a id='n1050' href='#n1050'>1050</a>
<a id='n1051' href='#n1051'>1051</a>
<a id='n1052' href='#n1052'>1052</a>
<a id='n1053' href='#n1053'>1053</a>
<a id='n1054' href='#n1054'>1054</a>
<a id='n1055' href='#n1055'>1055</a>
<a id='n1056' href='#n1056'>1056</a>
<a id='n1057' href='#n1057'>1057</a>
<a id='n1058' href='#n1058'>1058</a>
<a id='n1059' href='#n1059'>1059</a>
<a id='n1060' href='#n1060'>1060</a>
<a id='n1061' href='#n1061'>1061</a>
<a id='n1062' href='#n1062'>1062</a>
<a id='n1063' href='#n1063'>1063</a>
<a id='n1064' href='#n1064'>1064</a>
<a id='n1065' href='#n1065'>1065</a>
<a id='n1066' href='#n1066'>1066</a>
<a id='n1067' href='#n1067'>1067</a>
<a id='n1068' href='#n1068'>1068</a>
<a id='n1069' href='#n1069'>1069</a>
<a id='n1070' href='#n1070'>1070</a>
<a id='n1071' href='#n1071'>1071</a>
<a id='n1072' href='#n1072'>1072</a>
<a id='n1073' href='#n1073'>1073</a>
<a id='n1074' href='#n1074'>1074</a>
<a id='n1075' href='#n1075'>1075</a>
<a id='n1076' href='#n1076'>1076</a>
<a id='n1077' href='#n1077'>1077</a>
<a id='n1078' href='#n1078'>1078</a>
<a id='n1079' href='#n1079'>1079</a>
<a id='n1080' href='#n1080'>1080</a>
<a id='n1081' href='#n1081'>1081</a>
<a id='n1082' href='#n1082'>1082</a>
<a id='n1083' href='#n1083'>1083</a>
<a id='n1084' href='#n1084'>1084</a>
<a id='n1085' href='#n1085'>1085</a>
<a id='n1086' href='#n1086'>1086</a>
<a id='n1087' href='#n1087'>1087</a>
<a id='n1088' href='#n1088'>1088</a>
<a id='n1089' href='#n1089'>1089</a>
<a id='n1090' href='#n1090'>1090</a>
<a id='n1091' href='#n1091'>1091</a>
<a id='n1092' href='#n1092'>1092</a>
<a id='n1093' href='#n1093'>1093</a>
<a id='n1094' href='#n1094'>1094</a>
<a id='n1095' href='#n1095'>1095</a>
<a id='n1096' href='#n1096'>1096</a>
<a id='n1097' href='#n1097'>1097</a>
<a id='n1098' href='#n1098'>1098</a>
<a id='n1099' href='#n1099'>1099</a>
<a id='n1100' href='#n1100'>1100</a>
<a id='n1101' href='#n1101'>1101</a>
<a id='n1102' href='#n1102'>1102</a>
<a id='n1103' href='#n1103'>1103</a>
<a id='n1104' href='#n1104'>1104</a>
<a id='n1105' href='#n1105'>1105</a>
<a id='n1106' href='#n1106'>1106</a>
<a id='n1107' href='#n1107'>1107</a>
<a id='n1108' href='#n1108'>1108</a>
<a id='n1109' href='#n1109'>1109</a>
<a id='n1110' href='#n1110'>1110</a>
<a id='n1111' href='#n1111'>1111</a>
<a id='n1112' href='#n1112'>1112</a>
<a id='n1113' href='#n1113'>1113</a>
<a id='n1114' href='#n1114'>1114</a>
<a id='n1115' href='#n1115'>1115</a>
<a id='n1116' href='#n1116'>1116</a>
<a id='n1117' href='#n1117'>1117</a>
<a id='n1118' href='#n1118'>1118</a>
<a id='n1119' href='#n1119'>1119</a>
<a id='n1120' href='#n1120'>1120</a>
<a id='n1121' href='#n1121'>1121</a>
<a id='n1122' href='#n1122'>1122</a>
<a id='n1123' href='#n1123'>1123</a>
<a id='n1124' href='#n1124'>1124</a>
<a id='n1125' href='#n1125'>1125</a>
<a id='n1126' href='#n1126'>1126</a>
<a id='n1127' href='#n1127'>1127</a>
<a id='n1128' href='#n1128'>1128</a>
<a id='n1129' href='#n1129'>1129</a>
<a id='n1130' href='#n1130'>1130</a>
<a id='n1131' href='#n1131'>1131</a>
<a id='n1132' href='#n1132'>1132</a>
<a id='n1133' href='#n1133'>1133</a>
<a id='n1134' href='#n1134'>1134</a>
<a id='n1135' href='#n1135'>1135</a>
<a id='n1136' href='#n1136'>1136</a>
<a id='n1137' href='#n1137'>1137</a>
<a id='n1138' href='#n1138'>1138</a>
<a id='n1139' href='#n1139'>1139</a>
<a id='n1140' href='#n1140'>1140</a>
<a id='n1141' href='#n1141'>1141</a>
<a id='n1142' href='#n1142'>1142</a>
<a id='n1143' href='#n1143'>1143</a>
<a id='n1144' href='#n1144'>1144</a>
<a id='n1145' href='#n1145'>1145</a>
<a id='n1146' href='#n1146'>1146</a>
<a id='n1147' href='#n1147'>1147</a>
<a id='n1148' href='#n1148'>1148</a>
<a id='n1149' href='#n1149'>1149</a>
<a id='n1150' href='#n1150'>1150</a>
<a id='n1151' href='#n1151'>1151</a>
<a id='n1152' href='#n1152'>1152</a>
<a id='n1153' href='#n1153'>1153</a>
<a id='n1154' href='#n1154'>1154</a>
<a id='n1155' href='#n1155'>1155</a>
<a id='n1156' href='#n1156'>1156</a>
<a id='n1157' href='#n1157'>1157</a>
<a id='n1158' href='#n1158'>1158</a>
<a id='n1159' href='#n1159'>1159</a>
<a id='n1160' href='#n1160'>1160</a>
<a id='n1161' href='#n1161'>1161</a>
<a id='n1162' href='#n1162'>1162</a>
<a id='n1163' href='#n1163'>1163</a>
<a id='n1164' href='#n1164'>1164</a>
<a id='n1165' href='#n1165'>1165</a>
<a id='n1166' href='#n1166'>1166</a>
<a id='n1167' href='#n1167'>1167</a>
<a id='n1168' href='#n1168'>1168</a>
<a id='n1169' href='#n1169'>1169</a>
<a id='n1170' href='#n1170'>1170</a>
<a id='n1171' href='#n1171'>1171</a>
<a id='n1172' href='#n1172'>1172</a>
<a id='n1173' href='#n1173'>1173</a>
<a id='n1174' href='#n1174'>1174</a>
<a id='n1175' href='#n1175'>1175</a>
<a id='n1176' href='#n1176'>1176</a>
<a id='n1177' href='#n1177'>1177</a>
<a id='n1178' href='#n1178'>1178</a>
<a id='n1179' href='#n1179'>1179</a>
<a id='n1180' href='#n1180'>1180</a>
<a id='n1181' href='#n1181'>1181</a>
<a id='n1182' href='#n1182'>1182</a>
<a id='n1183' href='#n1183'>1183</a>
<a id='n1184' href='#n1184'>1184</a>
<a id='n1185' href='#n1185'>1185</a>
<a id='n1186' href='#n1186'>1186</a>
<a id='n1187' href='#n1187'>1187</a>
<a id='n1188' href='#n1188'>1188</a>
<a id='n1189' href='#n1189'>1189</a>
<a id='n1190' href='#n1190'>1190</a>
<a id='n1191' href='#n1191'>1191</a>
<a id='n1192' href='#n1192'>1192</a>
<a id='n1193' href='#n1193'>1193</a>
<a id='n1194' href='#n1194'>1194</a>
<a id='n1195' href='#n1195'>1195</a>
<a id='n1196' href='#n1196'>1196</a>
<a id='n1197' href='#n1197'>1197</a>
<a id='n1198' href='#n1198'>1198</a>
<a id='n1199' href='#n1199'>1199</a>
<a id='n1200' href='#n1200'>1200</a>
<a id='n1201' href='#n1201'>1201</a>
<a id='n1202' href='#n1202'>1202</a>
<a id='n1203' href='#n1203'>1203</a>
<a id='n1204' href='#n1204'>1204</a>
<a id='n1205' href='#n1205'>1205</a>
<a id='n1206' href='#n1206'>1206</a>
<a id='n1207' href='#n1207'>1207</a>
<a id='n1208' href='#n1208'>1208</a>
<a id='n1209' href='#n1209'>1209</a>
<a id='n1210' href='#n1210'>1210</a>
<a id='n1211' href='#n1211'>1211</a>
<a id='n1212' href='#n1212'>1212</a>
<a id='n1213' href='#n1213'>1213</a>
<a id='n1214' href='#n1214'>1214</a>
<a id='n1215' href='#n1215'>1215</a>
<a id='n1216' href='#n1216'>1216</a>
<a id='n1217' href='#n1217'>1217</a>
<a id='n1218' href='#n1218'>1218</a>
<a id='n1219' href='#n1219'>1219</a>
<a id='n1220' href='#n1220'>1220</a>
<a id='n1221' href='#n1221'>1221</a>
<a id='n1222' href='#n1222'>1222</a>
<a id='n1223' href='#n1223'>1223</a>
<a id='n1224' href='#n1224'>1224</a>
<a id='n1225' href='#n1225'>1225</a>
<a id='n1226' href='#n1226'>1226</a>
<a id='n1227' href='#n1227'>1227</a>
<a id='n1228' href='#n1228'>1228</a>
<a id='n1229' href='#n1229'>1229</a>
<a id='n1230' href='#n1230'>1230</a>
<a id='n1231' href='#n1231'>1231</a>
<a id='n1232' href='#n1232'>1232</a>
<a id='n1233' href='#n1233'>1233</a>
<a id='n1234' href='#n1234'>1234</a>
<a id='n1235' href='#n1235'>1235</a>
<a id='n1236' href='#n1236'>1236</a>
<a id='n1237' href='#n1237'>1237</a>
<a id='n1238' href='#n1238'>1238</a>
<a id='n1239' href='#n1239'>1239</a>
<a id='n1240' href='#n1240'>1240</a>
<a id='n1241' href='#n1241'>1241</a>
<a id='n1242' href='#n1242'>1242</a>
<a id='n1243' href='#n1243'>1243</a>
<a id='n1244' href='#n1244'>1244</a>
<a id='n1245' href='#n1245'>1245</a>
<a id='n1246' href='#n1246'>1246</a>
<a id='n1247' href='#n1247'>1247</a>
<a id='n1248' href='#n1248'>1248</a>
<a id='n1249' href='#n1249'>1249</a>
<a id='n1250' href='#n1250'>1250</a>
<a id='n1251' href='#n1251'>1251</a>
<a id='n1252' href='#n1252'>1252</a>
<a id='n1253' href='#n1253'>1253</a>
<a id='n1254' href='#n1254'>1254</a>
<a id='n1255' href='#n1255'>1255</a>
<a id='n1256' href='#n1256'>1256</a>
<a id='n1257' href='#n1257'>1257</a>
<a id='n1258' href='#n1258'>1258</a>
<a id='n1259' href='#n1259'>1259</a>
<a id='n1260' href='#n1260'>1260</a>
<a id='n1261' href='#n1261'>1261</a>
<a id='n1262' href='#n1262'>1262</a>
<a id='n1263' href='#n1263'>1263</a>
<a id='n1264' href='#n1264'>1264</a>
<a id='n1265' href='#n1265'>1265</a>
<a id='n1266' href='#n1266'>1266</a>
<a id='n1267' href='#n1267'>1267</a>
<a id='n1268' href='#n1268'>1268</a>
<a id='n1269' href='#n1269'>1269</a>
<a id='n1270' href='#n1270'>1270</a>
<a id='n1271' href='#n1271'>1271</a>
<a id='n1272' href='#n1272'>1272</a>
<a id='n1273' href='#n1273'>1273</a>
<a id='n1274' href='#n1274'>1274</a>
<a id='n1275' href='#n1275'>1275</a>
<a id='n1276' href='#n1276'>1276</a>
<a id='n1277' href='#n1277'>1277</a>
<a id='n1278' href='#n1278'>1278</a>
<a id='n1279' href='#n1279'>1279</a>
<a id='n1280' href='#n1280'>1280</a>
<a id='n1281' href='#n1281'>1281</a>
<a id='n1282' href='#n1282'>1282</a>
<a id='n1283' href='#n1283'>1283</a>
<a id='n1284' href='#n1284'>1284</a>
<a id='n1285' href='#n1285'>1285</a>
<a id='n1286' href='#n1286'>1286</a>
<a id='n1287' href='#n1287'>1287</a>
<a id='n1288' href='#n1288'>1288</a>
<a id='n1289' href='#n1289'>1289</a>
<a id='n1290' href='#n1290'>1290</a>
<a id='n1291' href='#n1291'>1291</a>
<a id='n1292' href='#n1292'>1292</a>
<a id='n1293' href='#n1293'>1293</a>
<a id='n1294' href='#n1294'>1294</a>
<a id='n1295' href='#n1295'>1295</a>
<a id='n1296' href='#n1296'>1296</a>
<a id='n1297' href='#n1297'>1297</a>
<a id='n1298' href='#n1298'>1298</a>
<a id='n1299' href='#n1299'>1299</a>
<a id='n1300' href='#n1300'>1300</a>
<a id='n1301' href='#n1301'>1301</a>
<a id='n1302' href='#n1302'>1302</a>
<a id='n1303' href='#n1303'>1303</a>
<a id='n1304' href='#n1304'>1304</a>
<a id='n1305' href='#n1305'>1305</a>
<a id='n1306' href='#n1306'>1306</a>
<a id='n1307' href='#n1307'>1307</a>
<a id='n1308' href='#n1308'>1308</a>
<a id='n1309' href='#n1309'>1309</a>
<a id='n1310' href='#n1310'>1310</a>
<a id='n1311' href='#n1311'>1311</a>
<a id='n1312' href='#n1312'>1312</a>
<a id='n1313' href='#n1313'>1313</a>
<a id='n1314' href='#n1314'>1314</a>
<a id='n1315' href='#n1315'>1315</a>
<a id='n1316' href='#n1316'>1316</a>
<a id='n1317' href='#n1317'>1317</a>
<a id='n1318' href='#n1318'>1318</a>
<a id='n1319' href='#n1319'>1319</a>
<a id='n1320' href='#n1320'>1320</a>
<a id='n1321' href='#n1321'>1321</a>
<a id='n1322' href='#n1322'>1322</a>
<a id='n1323' href='#n1323'>1323</a>
<a id='n1324' href='#n1324'>1324</a>
<a id='n1325' href='#n1325'>1325</a>
<a id='n1326' href='#n1326'>1326</a>
<a id='n1327' href='#n1327'>1327</a>
<a id='n1328' href='#n1328'>1328</a>
<a id='n1329' href='#n1329'>1329</a>
<a id='n1330' href='#n1330'>1330</a>
<a id='n1331' href='#n1331'>1331</a>
<a id='n1332' href='#n1332'>1332</a>
<a id='n1333' href='#n1333'>1333</a>
<a id='n1334' href='#n1334'>1334</a>
<a id='n1335' href='#n1335'>1335</a>
<a id='n1336' href='#n1336'>1336</a>
<a id='n1337' href='#n1337'>1337</a>
<a id='n1338' href='#n1338'>1338</a>
<a id='n1339' href='#n1339'>1339</a>
<a id='n1340' href='#n1340'>1340</a>
<a id='n1341' href='#n1341'>1341</a>
<a id='n1342' href='#n1342'>1342</a>
<a id='n1343' href='#n1343'>1343</a>
<a id='n1344' href='#n1344'>1344</a>
<a id='n1345' href='#n1345'>1345</a>
<a id='n1346' href='#n1346'>1346</a>
<a id='n1347' href='#n1347'>1347</a>
<a id='n1348' href='#n1348'>1348</a>
<a id='n1349' href='#n1349'>1349</a>
<a id='n1350' href='#n1350'>1350</a>
<a id='n1351' href='#n1351'>1351</a>
<a id='n1352' href='#n1352'>1352</a>
<a id='n1353' href='#n1353'>1353</a>
<a id='n1354' href='#n1354'>1354</a>
<a id='n1355' href='#n1355'>1355</a>
<a id='n1356' href='#n1356'>1356</a>
<a id='n1357' href='#n1357'>1357</a>
<a id='n1358' href='#n1358'>1358</a>
<a id='n1359' href='#n1359'>1359</a>
<a id='n1360' href='#n1360'>1360</a>
<a id='n1361' href='#n1361'>1361</a>
<a id='n1362' href='#n1362'>1362</a>
<a id='n1363' href='#n1363'>1363</a>
<a id='n1364' href='#n1364'>1364</a>
<a id='n1365' href='#n1365'>1365</a>
<a id='n1366' href='#n1366'>1366</a>
<a id='n1367' href='#n1367'>1367</a>
<a id='n1368' href='#n1368'>1368</a>
<a id='n1369' href='#n1369'>1369</a>
<a id='n1370' href='#n1370'>1370</a>
<a id='n1371' href='#n1371'>1371</a>
<a id='n1372' href='#n1372'>1372</a>
<a id='n1373' href='#n1373'>1373</a>
<a id='n1374' href='#n1374'>1374</a>
<a id='n1375' href='#n1375'>1375</a>
<a id='n1376' href='#n1376'>1376</a>
<a id='n1377' href='#n1377'>1377</a>
<a id='n1378' href='#n1378'>1378</a>
<a id='n1379' href='#n1379'>1379</a>
<a id='n1380' href='#n1380'>1380</a>
<a id='n1381' href='#n1381'>1381</a>
<a id='n1382' href='#n1382'>1382</a>
<a id='n1383' href='#n1383'>1383</a>
<a id='n1384' href='#n1384'>1384</a>
<a id='n1385' href='#n1385'>1385</a>
<a id='n1386' href='#n1386'>1386</a>
<a id='n1387' href='#n1387'>1387</a>
<a id='n1388' href='#n1388'>1388</a>
<a id='n1389' href='#n1389'>1389</a>
<a id='n1390' href='#n1390'>1390</a>
<a id='n1391' href='#n1391'>1391</a>
<a id='n1392' href='#n1392'>1392</a>
<a id='n1393' href='#n1393'>1393</a>
<a id='n1394' href='#n1394'>1394</a>
<a id='n1395' href='#n1395'>1395</a>
<a id='n1396' href='#n1396'>1396</a>
<a id='n1397' href='#n1397'>1397</a>
<a id='n1398' href='#n1398'>1398</a>
<a id='n1399' href='#n1399'>1399</a>
<a id='n1400' href='#n1400'>1400</a>
<a id='n1401' href='#n1401'>1401</a>
<a id='n1402' href='#n1402'>1402</a>
<a id='n1403' href='#n1403'>1403</a>
<a id='n1404' href='#n1404'>1404</a>
<a id='n1405' href='#n1405'>1405</a>
<a id='n1406' href='#n1406'>1406</a>
<a id='n1407' href='#n1407'>1407</a>
<a id='n1408' href='#n1408'>1408</a>
<a id='n1409' href='#n1409'>1409</a>
<a id='n1410' href='#n1410'>1410</a>
<a id='n1411' href='#n1411'>1411</a>
<a id='n1412' href='#n1412'>1412</a>
<a id='n1413' href='#n1413'>1413</a>
<a id='n1414' href='#n1414'>1414</a>
<a id='n1415' href='#n1415'>1415</a>
<a id='n1416' href='#n1416'>1416</a>
<a id='n1417' href='#n1417'>1417</a>
<a id='n1418' href='#n1418'>1418</a>
<a id='n1419' href='#n1419'>1419</a>
<a id='n1420' href='#n1420'>1420</a>
<a id='n1421' href='#n1421'>1421</a>
<a id='n1422' href='#n1422'>1422</a>
<a id='n1423' href='#n1423'>1423</a>
<a id='n1424' href='#n1424'>1424</a>
<a id='n1425' href='#n1425'>1425</a>
<a id='n1426' href='#n1426'>1426</a>
<a id='n1427' href='#n1427'>1427</a>
<a id='n1428' href='#n1428'>1428</a>
<a id='n1429' href='#n1429'>1429</a>
<a id='n1430' href='#n1430'>1430</a>
<a id='n1431' href='#n1431'>1431</a>
<a id='n1432' href='#n1432'>1432</a>
<a id='n1433' href='#n1433'>1433</a>
<a id='n1434' href='#n1434'>1434</a>
<a id='n1435' href='#n1435'>1435</a>
<a id='n1436' href='#n1436'>1436</a>
<a id='n1437' href='#n1437'>1437</a>
<a id='n1438' href='#n1438'>1438</a>
<a id='n1439' href='#n1439'>1439</a>
<a id='n1440' href='#n1440'>1440</a>
<a id='n1441' href='#n1441'>1441</a>
<a id='n1442' href='#n1442'>1442</a>
<a id='n1443' href='#n1443'>1443</a>
<a id='n1444' href='#n1444'>1444</a>
<a id='n1445' href='#n1445'>1445</a>
<a id='n1446' href='#n1446'>1446</a>
<a id='n1447' href='#n1447'>1447</a>
<a id='n1448' href='#n1448'>1448</a>
<a id='n1449' href='#n1449'>1449</a>
<a id='n1450' href='#n1450'>1450</a>
<a id='n1451' href='#n1451'>1451</a>
<a id='n1452' href='#n1452'>1452</a>
<a id='n1453' href='#n1453'>1453</a>
<a id='n1454' href='#n1454'>1454</a>
<a id='n1455' href='#n1455'>1455</a>
<a id='n1456' href='#n1456'>1456</a>
<a id='n1457' href='#n1457'>1457</a>
<a id='n1458' href='#n1458'>1458</a>
<a id='n1459' href='#n1459'>1459</a>
<a id='n1460' href='#n1460'>1460</a>
<a id='n1461' href='#n1461'>1461</a>
<a id='n1462' href='#n1462'>1462</a>
<a id='n1463' href='#n1463'>1463</a>
<a id='n1464' href='#n1464'>1464</a>
<a id='n1465' href='#n1465'>1465</a>
<a id='n1466' href='#n1466'>1466</a>
<a id='n1467' href='#n1467'>1467</a>
<a id='n1468' href='#n1468'>1468</a>
<a id='n1469' href='#n1469'>1469</a>
<a id='n1470' href='#n1470'>1470</a>
<a id='n1471' href='#n1471'>1471</a>
<a id='n1472' href='#n1472'>1472</a>
<a id='n1473' href='#n1473'>1473</a>
<a id='n1474' href='#n1474'>1474</a>
<a id='n1475' href='#n1475'>1475</a>
<a id='n1476' href='#n1476'>1476</a>
<a id='n1477' href='#n1477'>1477</a>
<a id='n1478' href='#n1478'>1478</a>
<a id='n1479' href='#n1479'>1479</a>
<a id='n1480' href='#n1480'>1480</a>
<a id='n1481' href='#n1481'>1481</a>
<a id='n1482' href='#n1482'>1482</a>
<a id='n1483' href='#n1483'>1483</a>
<a id='n1484' href='#n1484'>1484</a>
<a id='n1485' href='#n1485'>1485</a>
<a id='n1486' href='#n1486'>1486</a>
<a id='n1487' href='#n1487'>1487</a>
<a id='n1488' href='#n1488'>1488</a>
<a id='n1489' href='#n1489'>1489</a>
<a id='n1490' href='#n1490'>1490</a>
<a id='n1491' href='#n1491'>1491</a>
<a id='n1492' href='#n1492'>1492</a>
<a id='n1493' href='#n1493'>1493</a>
<a id='n1494' href='#n1494'>1494</a>
<a id='n1495' href='#n1495'>1495</a>
<a id='n1496' href='#n1496'>1496</a>
<a id='n1497' href='#n1497'>1497</a>
<a id='n1498' href='#n1498'>1498</a>
<a id='n1499' href='#n1499'>1499</a>
<a id='n1500' href='#n1500'>1500</a>
<a id='n1501' href='#n1501'>1501</a>
<a id='n1502' href='#n1502'>1502</a>
<a id='n1503' href='#n1503'>1503</a>
<a id='n1504' href='#n1504'>1504</a>
<a id='n1505' href='#n1505'>1505</a>
<a id='n1506' href='#n1506'>1506</a>
<a id='n1507' href='#n1507'>1507</a>
<a id='n1508' href='#n1508'>1508</a>
<a id='n1509' href='#n1509'>1509</a>
<a id='n1510' href='#n1510'>1510</a>
<a id='n1511' href='#n1511'>1511</a>
<a id='n1512' href='#n1512'>1512</a>
<a id='n1513' href='#n1513'>1513</a>
<a id='n1514' href='#n1514'>1514</a>
<a id='n1515' href='#n1515'>1515</a>
<a id='n1516' href='#n1516'>1516</a>
<a id='n1517' href='#n1517'>1517</a>
<a id='n1518' href='#n1518'>1518</a>
<a id='n1519' href='#n1519'>1519</a>
<a id='n1520' href='#n1520'>1520</a>
<a id='n1521' href='#n1521'>1521</a>
<a id='n1522' href='#n1522'>1522</a>
<a id='n1523' href='#n1523'>1523</a>
<a id='n1524' href='#n1524'>1524</a>
<a id='n1525' href='#n1525'>1525</a>
<a id='n1526' href='#n1526'>1526</a>
<a id='n1527' href='#n1527'>1527</a>
<a id='n1528' href='#n1528'>1528</a>
<a id='n1529' href='#n1529'>1529</a>
<a id='n1530' href='#n1530'>1530</a>
<a id='n1531' href='#n1531'>1531</a>
<a id='n1532' href='#n1532'>1532</a>
<a id='n1533' href='#n1533'>1533</a>
<a id='n1534' href='#n1534'>1534</a>
<a id='n1535' href='#n1535'>1535</a>
<a id='n1536' href='#n1536'>1536</a>
<a id='n1537' href='#n1537'>1537</a>
<a id='n1538' href='#n1538'>1538</a>
<a id='n1539' href='#n1539'>1539</a>
<a id='n1540' href='#n1540'>1540</a>
<a id='n1541' href='#n1541'>1541</a>
<a id='n1542' href='#n1542'>1542</a>
<a id='n1543' href='#n1543'>1543</a>
<a id='n1544' href='#n1544'>1544</a>
<a id='n1545' href='#n1545'>1545</a>
<a id='n1546' href='#n1546'>1546</a>
<a id='n1547' href='#n1547'>1547</a>
<a id='n1548' href='#n1548'>1548</a>
<a id='n1549' href='#n1549'>1549</a>
<a id='n1550' href='#n1550'>1550</a>
<a id='n1551' href='#n1551'>1551</a>
<a id='n1552' href='#n1552'>1552</a>
<a id='n1553' href='#n1553'>1553</a>
<a id='n1554' href='#n1554'>1554</a>
<a id='n1555' href='#n1555'>1555</a>
<a id='n1556' href='#n1556'>1556</a>
<a id='n1557' href='#n1557'>1557</a>
<a id='n1558' href='#n1558'>1558</a>
<a id='n1559' href='#n1559'>1559</a>
<a id='n1560' href='#n1560'>1560</a>
<a id='n1561' href='#n1561'>1561</a>
<a id='n1562' href='#n1562'>1562</a>
<a id='n1563' href='#n1563'>1563</a>
<a id='n1564' href='#n1564'>1564</a>
<a id='n1565' href='#n1565'>1565</a>
<a id='n1566' href='#n1566'>1566</a>
<a id='n1567' href='#n1567'>1567</a>
<a id='n1568' href='#n1568'>1568</a>
<a id='n1569' href='#n1569'>1569</a>
<a id='n1570' href='#n1570'>1570</a>
<a id='n1571' href='#n1571'>1571</a>
<a id='n1572' href='#n1572'>1572</a>
<a id='n1573' href='#n1573'>1573</a>
<a id='n1574' href='#n1574'>1574</a>
<a id='n1575' href='#n1575'>1575</a>
<a id='n1576' href='#n1576'>1576</a>
<a id='n1577' href='#n1577'>1577</a>
<a id='n1578' href='#n1578'>1578</a>
<a id='n1579' href='#n1579'>1579</a>
<a id='n1580' href='#n1580'>1580</a>
<a id='n1581' href='#n1581'>1581</a>
<a id='n1582' href='#n1582'>1582</a>
<a id='n1583' href='#n1583'>1583</a>
<a id='n1584' href='#n1584'>1584</a>
<a id='n1585' href='#n1585'>1585</a>
<a id='n1586' href='#n1586'>1586</a>
<a id='n1587' href='#n1587'>1587</a>
<a id='n1588' href='#n1588'>1588</a>
<a id='n1589' href='#n1589'>1589</a>
<a id='n1590' href='#n1590'>1590</a>
<a id='n1591' href='#n1591'>1591</a>
<a id='n1592' href='#n1592'>1592</a>
<a id='n1593' href='#n1593'>1593</a>
<a id='n1594' href='#n1594'>1594</a>
<a id='n1595' href='#n1595'>1595</a>
<a id='n1596' href='#n1596'>1596</a>
<a id='n1597' href='#n1597'>1597</a>
<a id='n1598' href='#n1598'>1598</a>
<a id='n1599' href='#n1599'>1599</a>
<a id='n1600' href='#n1600'>1600</a>
<a id='n1601' href='#n1601'>1601</a>
<a id='n1602' href='#n1602'>1602</a>
<a id='n1603' href='#n1603'>1603</a>
<a id='n1604' href='#n1604'>1604</a>
<a id='n1605' href='#n1605'>1605</a>
<a id='n1606' href='#n1606'>1606</a>
<a id='n1607' href='#n1607'>1607</a>
<a id='n1608' href='#n1608'>1608</a>
<a id='n1609' href='#n1609'>1609</a>
<a id='n1610' href='#n1610'>1610</a>
<a id='n1611' href='#n1611'>1611</a>
<a id='n1612' href='#n1612'>1612</a>
<a id='n1613' href='#n1613'>1613</a>
<a id='n1614' href='#n1614'>1614</a>
<a id='n1615' href='#n1615'>1615</a>
<a id='n1616' href='#n1616'>1616</a>
<a id='n1617' href='#n1617'>1617</a>
<a id='n1618' href='#n1618'>1618</a>
<a id='n1619' href='#n1619'>1619</a>
<a id='n1620' href='#n1620'>1620</a>
<a id='n1621' href='#n1621'>1621</a>
<a id='n1622' href='#n1622'>1622</a>
<a id='n1623' href='#n1623'>1623</a>
<a id='n1624' href='#n1624'>1624</a>
<a id='n1625' href='#n1625'>1625</a>
<a id='n1626' href='#n1626'>1626</a>
<a id='n1627' href='#n1627'>1627</a>
<a id='n1628' href='#n1628'>1628</a>
<a id='n1629' href='#n1629'>1629</a>
<a id='n1630' href='#n1630'>1630</a>
<a id='n1631' href='#n1631'>1631</a>
<a id='n1632' href='#n1632'>1632</a>
<a id='n1633' href='#n1633'>1633</a>
<a id='n1634' href='#n1634'>1634</a>
<a id='n1635' href='#n1635'>1635</a>
<a id='n1636' href='#n1636'>1636</a>
<a id='n1637' href='#n1637'>1637</a>
<a id='n1638' href='#n1638'>1638</a>
<a id='n1639' href='#n1639'>1639</a>
<a id='n1640' href='#n1640'>1640</a>
<a id='n1641' href='#n1641'>1641</a>
<a id='n1642' href='#n1642'>1642</a>
<a id='n1643' href='#n1643'>1643</a>
<a id='n1644' href='#n1644'>1644</a>
<a id='n1645' href='#n1645'>1645</a>
<a id='n1646' href='#n1646'>1646</a>
<a id='n1647' href='#n1647'>1647</a>
<a id='n1648' href='#n1648'>1648</a>
<a id='n1649' href='#n1649'>1649</a>
<a id='n1650' href='#n1650'>1650</a>
<a id='n1651' href='#n1651'>1651</a>
<a id='n1652' href='#n1652'>1652</a>
<a id='n1653' href='#n1653'>1653</a>
<a id='n1654' href='#n1654'>1654</a>
<a id='n1655' href='#n1655'>1655</a>
<a id='n1656' href='#n1656'>1656</a>
<a id='n1657' href='#n1657'>1657</a>
<a id='n1658' href='#n1658'>1658</a>
<a id='n1659' href='#n1659'>1659</a>
<a id='n1660' href='#n1660'>1660</a>
<a id='n1661' href='#n1661'>1661</a>
<a id='n1662' href='#n1662'>1662</a>
<a id='n1663' href='#n1663'>1663</a>
<a id='n1664' href='#n1664'>1664</a>
<a id='n1665' href='#n1665'>1665</a>
<a id='n1666' href='#n1666'>1666</a>
<a id='n1667' href='#n1667'>1667</a>
<a id='n1668' href='#n1668'>1668</a>
<a id='n1669' href='#n1669'>1669</a>
<a id='n1670' href='#n1670'>1670</a>
<a id='n1671' href='#n1671'>1671</a>
<a id='n1672' href='#n1672'>1672</a>
<a id='n1673' href='#n1673'>1673</a>
<a id='n1674' href='#n1674'>1674</a>
<a id='n1675' href='#n1675'>1675</a>
<a id='n1676' href='#n1676'>1676</a>
<a id='n1677' href='#n1677'>1677</a>
<a id='n1678' href='#n1678'>1678</a>
<a id='n1679' href='#n1679'>1679</a>
<a id='n1680' href='#n1680'>1680</a>
<a id='n1681' href='#n1681'>1681</a>
<a id='n1682' href='#n1682'>1682</a>
<a id='n1683' href='#n1683'>1683</a>
<a id='n1684' href='#n1684'>1684</a>
<a id='n1685' href='#n1685'>1685</a>
<a id='n1686' href='#n1686'>1686</a>
<a id='n1687' href='#n1687'>1687</a>
<a id='n1688' href='#n1688'>1688</a>
<a id='n1689' href='#n1689'>1689</a>
<a id='n1690' href='#n1690'>1690</a>
<a id='n1691' href='#n1691'>1691</a>
<a id='n1692' href='#n1692'>1692</a>
<a id='n1693' href='#n1693'>1693</a>
<a id='n1694' href='#n1694'>1694</a>
<a id='n1695' href='#n1695'>1695</a>
<a id='n1696' href='#n1696'>1696</a>
<a id='n1697' href='#n1697'>1697</a>
<a id='n1698' href='#n1698'>1698</a>
<a id='n1699' href='#n1699'>1699</a>
<a id='n1700' href='#n1700'>1700</a>
<a id='n1701' href='#n1701'>1701</a>
<a id='n1702' href='#n1702'>1702</a>
<a id='n1703' href='#n1703'>1703</a>
<a id='n1704' href='#n1704'>1704</a>
<a id='n1705' href='#n1705'>1705</a>
<a id='n1706' href='#n1706'>1706</a>
<a id='n1707' href='#n1707'>1707</a>
<a id='n1708' href='#n1708'>1708</a>
<a id='n1709' href='#n1709'>1709</a>
<a id='n1710' href='#n1710'>1710</a>
<a id='n1711' href='#n1711'>1711</a>
<a id='n1712' href='#n1712'>1712</a>
<a id='n1713' href='#n1713'>1713</a>
<a id='n1714' href='#n1714'>1714</a>
<a id='n1715' href='#n1715'>1715</a>
<a id='n1716' href='#n1716'>1716</a>
<a id='n1717' href='#n1717'>1717</a>
<a id='n1718' href='#n1718'>1718</a>
<a id='n1719' href='#n1719'>1719</a>
<a id='n1720' href='#n1720'>1720</a>
<a id='n1721' href='#n1721'>1721</a>
<a id='n1722' href='#n1722'>1722</a>
<a id='n1723' href='#n1723'>1723</a>
<a id='n1724' href='#n1724'>1724</a>
<a id='n1725' href='#n1725'>1725</a>
<a id='n1726' href='#n1726'>1726</a>
<a id='n1727' href='#n1727'>1727</a>
<a id='n1728' href='#n1728'>1728</a>
<a id='n1729' href='#n1729'>1729</a>
<a id='n1730' href='#n1730'>1730</a>
<a id='n1731' href='#n1731'>1731</a>
<a id='n1732' href='#n1732'>1732</a>
<a id='n1733' href='#n1733'>1733</a>
<a id='n1734' href='#n1734'>1734</a>
<a id='n1735' href='#n1735'>1735</a>
<a id='n1736' href='#n1736'>1736</a>
<a id='n1737' href='#n1737'>1737</a>
<a id='n1738' href='#n1738'>1738</a>
<a id='n1739' href='#n1739'>1739</a>
<a id='n1740' href='#n1740'>1740</a>
<a id='n1741' href='#n1741'>1741</a>
<a id='n1742' href='#n1742'>1742</a>
<a id='n1743' href='#n1743'>1743</a>
<a id='n1744' href='#n1744'>1744</a>
<a id='n1745' href='#n1745'>1745</a>
<a id='n1746' href='#n1746'>1746</a>
<a id='n1747' href='#n1747'>1747</a>
<a id='n1748' href='#n1748'>1748</a>
<a id='n1749' href='#n1749'>1749</a>
<a id='n1750' href='#n1750'>1750</a>
<a id='n1751' href='#n1751'>1751</a>
<a id='n1752' href='#n1752'>1752</a>
<a id='n1753' href='#n1753'>1753</a>
<a id='n1754' href='#n1754'>1754</a>
<a id='n1755' href='#n1755'>1755</a>
<a id='n1756' href='#n1756'>1756</a>
<a id='n1757' href='#n1757'>1757</a>
<a id='n1758' href='#n1758'>1758</a>
<a id='n1759' href='#n1759'>1759</a>
<a id='n1760' href='#n1760'>1760</a>
<a id='n1761' href='#n1761'>1761</a>
<a id='n1762' href='#n1762'>1762</a>
<a id='n1763' href='#n1763'>1763</a>
<a id='n1764' href='#n1764'>1764</a>
<a id='n1765' href='#n1765'>1765</a>
<a id='n1766' href='#n1766'>1766</a>
<a id='n1767' href='#n1767'>1767</a>
<a id='n1768' href='#n1768'>1768</a>
<a id='n1769' href='#n1769'>1769</a>
<a id='n1770' href='#n1770'>1770</a>
<a id='n1771' href='#n1771'>1771</a>
<a id='n1772' href='#n1772'>1772</a>
<a id='n1773' href='#n1773'>1773</a>
<a id='n1774' href='#n1774'>1774</a>
<a id='n1775' href='#n1775'>1775</a>
<a id='n1776' href='#n1776'>1776</a>
<a id='n1777' href='#n1777'>1777</a>
<a id='n1778' href='#n1778'>1778</a>
<a id='n1779' href='#n1779'>1779</a>
<a id='n1780' href='#n1780'>1780</a>
<a id='n1781' href='#n1781'>1781</a>
<a id='n1782' href='#n1782'>1782</a>
<a id='n1783' href='#n1783'>1783</a>
<a id='n1784' href='#n1784'>1784</a>
<a id='n1785' href='#n1785'>1785</a>
<a id='n1786' href='#n1786'>1786</a>
<a id='n1787' href='#n1787'>1787</a>
<a id='n1788' href='#n1788'>1788</a>
<a id='n1789' href='#n1789'>1789</a>
<a id='n1790' href='#n1790'>1790</a>
<a id='n1791' href='#n1791'>1791</a>
<a id='n1792' href='#n1792'>1792</a>
<a id='n1793' href='#n1793'>1793</a>
<a id='n1794' href='#n1794'>1794</a>
<a id='n1795' href='#n1795'>1795</a>
<a id='n1796' href='#n1796'>1796</a>
<a id='n1797' href='#n1797'>1797</a>
<a id='n1798' href='#n1798'>1798</a>
<a id='n1799' href='#n1799'>1799</a>
<a id='n1800' href='#n1800'>1800</a>
<a id='n1801' href='#n1801'>1801</a>
<a id='n1802' href='#n1802'>1802</a>
<a id='n1803' href='#n1803'>1803</a>
<a id='n1804' href='#n1804'>1804</a>
<a id='n1805' href='#n1805'>1805</a>
<a id='n1806' href='#n1806'>1806</a>
<a id='n1807' href='#n1807'>1807</a>
<a id='n1808' href='#n1808'>1808</a>
<a id='n1809' href='#n1809'>1809</a>
<a id='n1810' href='#n1810'>1810</a>
<a id='n1811' href='#n1811'>1811</a>
<a id='n1812' href='#n1812'>1812</a>
<a id='n1813' href='#n1813'>1813</a>
<a id='n1814' href='#n1814'>1814</a>
<a id='n1815' href='#n1815'>1815</a>
<a id='n1816' href='#n1816'>1816</a>
<a id='n1817' href='#n1817'>1817</a>
<a id='n1818' href='#n1818'>1818</a>
<a id='n1819' href='#n1819'>1819</a>
<a id='n1820' href='#n1820'>1820</a>
<a id='n1821' href='#n1821'>1821</a>
<a id='n1822' href='#n1822'>1822</a>
<a id='n1823' href='#n1823'>1823</a>
<a id='n1824' href='#n1824'>1824</a>
<a id='n1825' href='#n1825'>1825</a>
<a id='n1826' href='#n1826'>1826</a>
<a id='n1827' href='#n1827'>1827</a>
<a id='n1828' href='#n1828'>1828</a>
<a id='n1829' href='#n1829'>1829</a>
<a id='n1830' href='#n1830'>1830</a>
<a id='n1831' href='#n1831'>1831</a>
<a id='n1832' href='#n1832'>1832</a>
<a id='n1833' href='#n1833'>1833</a>
<a id='n1834' href='#n1834'>1834</a>
<a id='n1835' href='#n1835'>1835</a>
<a id='n1836' href='#n1836'>1836</a>
<a id='n1837' href='#n1837'>1837</a>
<a id='n1838' href='#n1838'>1838</a>
<a id='n1839' href='#n1839'>1839</a>
<a id='n1840' href='#n1840'>1840</a>
<a id='n1841' href='#n1841'>1841</a>
<a id='n1842' href='#n1842'>1842</a>
<a id='n1843' href='#n1843'>1843</a>
<a id='n1844' href='#n1844'>1844</a>
<a id='n1845' href='#n1845'>1845</a>
<a id='n1846' href='#n1846'>1846</a>
<a id='n1847' href='#n1847'>1847</a>
<a id='n1848' href='#n1848'>1848</a>
<a id='n1849' href='#n1849'>1849</a>
<a id='n1850' href='#n1850'>1850</a>
<a id='n1851' href='#n1851'>1851</a>
<a id='n1852' href='#n1852'>1852</a>
<a id='n1853' href='#n1853'>1853</a>
<a id='n1854' href='#n1854'>1854</a>
<a id='n1855' href='#n1855'>1855</a>
<a id='n1856' href='#n1856'>1856</a>
<a id='n1857' href='#n1857'>1857</a>
<a id='n1858' href='#n1858'>1858</a>
<a id='n1859' href='#n1859'>1859</a>
<a id='n1860' href='#n1860'>1860</a>
<a id='n1861' href='#n1861'>1861</a>
<a id='n1862' href='#n1862'>1862</a>
<a id='n1863' href='#n1863'>1863</a>
<a id='n1864' href='#n1864'>1864</a>
<a id='n1865' href='#n1865'>1865</a>
<a id='n1866' href='#n1866'>1866</a>
<a id='n1867' href='#n1867'>1867</a>
<a id='n1868' href='#n1868'>1868</a>
<a id='n1869' href='#n1869'>1869</a>
<a id='n1870' href='#n1870'>1870</a>
<a id='n1871' href='#n1871'>1871</a>
<a id='n1872' href='#n1872'>1872</a>
<a id='n1873' href='#n1873'>1873</a>
<a id='n1874' href='#n1874'>1874</a>
<a id='n1875' href='#n1875'>1875</a>
<a id='n1876' href='#n1876'>1876</a>
<a id='n1877' href='#n1877'>1877</a>
<a id='n1878' href='#n1878'>1878</a>
<a id='n1879' href='#n1879'>1879</a>
<a id='n1880' href='#n1880'>1880</a>
<a id='n1881' href='#n1881'>1881</a>
<a id='n1882' href='#n1882'>1882</a>
<a id='n1883' href='#n1883'>1883</a>
<a id='n1884' href='#n1884'>1884</a>
<a id='n1885' href='#n1885'>1885</a>
<a id='n1886' href='#n1886'>1886</a>
<a id='n1887' href='#n1887'>1887</a>
<a id='n1888' href='#n1888'>1888</a>
<a id='n1889' href='#n1889'>1889</a>
<a id='n1890' href='#n1890'>1890</a>
<a id='n1891' href='#n1891'>1891</a>
<a id='n1892' href='#n1892'>1892</a>
<a id='n1893' href='#n1893'>1893</a>
<a id='n1894' href='#n1894'>1894</a>
<a id='n1895' href='#n1895'>1895</a>
<a id='n1896' href='#n1896'>1896</a>
<a id='n1897' href='#n1897'>1897</a>
<a id='n1898' href='#n1898'>1898</a>
<a id='n1899' href='#n1899'>1899</a>
<a id='n1900' href='#n1900'>1900</a>
<a id='n1901' href='#n1901'>1901</a>
<a id='n1902' href='#n1902'>1902</a>
<a id='n1903' href='#n1903'>1903</a>
<a id='n1904' href='#n1904'>1904</a>
<a id='n1905' href='#n1905'>1905</a>
<a id='n1906' href='#n1906'>1906</a>
<a id='n1907' href='#n1907'>1907</a>
<a id='n1908' href='#n1908'>1908</a>
<a id='n1909' href='#n1909'>1909</a>
<a id='n1910' href='#n1910'>1910</a>
<a id='n1911' href='#n1911'>1911</a>
<a id='n1912' href='#n1912'>1912</a>
<a id='n1913' href='#n1913'>1913</a>
<a id='n1914' href='#n1914'>1914</a>
<a id='n1915' href='#n1915'>1915</a>
<a id='n1916' href='#n1916'>1916</a>
<a id='n1917' href='#n1917'>1917</a>
<a id='n1918' href='#n1918'>1918</a>
<a id='n1919' href='#n1919'>1919</a>
<a id='n1920' href='#n1920'>1920</a>
<a id='n1921' href='#n1921'>1921</a>
<a id='n1922' href='#n1922'>1922</a>
<a id='n1923' href='#n1923'>1923</a>
<a id='n1924' href='#n1924'>1924</a>
<a id='n1925' href='#n1925'>1925</a>
<a id='n1926' href='#n1926'>1926</a>
<a id='n1927' href='#n1927'>1927</a>
<a id='n1928' href='#n1928'>1928</a>
<a id='n1929' href='#n1929'>1929</a>
<a id='n1930' href='#n1930'>1930</a>
<a id='n1931' href='#n1931'>1931</a>
<a id='n1932' href='#n1932'>1932</a>
<a id='n1933' href='#n1933'>1933</a>
<a id='n1934' href='#n1934'>1934</a>
<a id='n1935' href='#n1935'>1935</a>
<a id='n1936' href='#n1936'>1936</a>
<a id='n1937' href='#n1937'>1937</a>
<a id='n1938' href='#n1938'>1938</a>
<a id='n1939' href='#n1939'>1939</a>
<a id='n1940' href='#n1940'>1940</a>
<a id='n1941' href='#n1941'>1941</a>
<a id='n1942' href='#n1942'>1942</a>
<a id='n1943' href='#n1943'>1943</a>
<a id='n1944' href='#n1944'>1944</a>
<a id='n1945' href='#n1945'>1945</a>
<a id='n1946' href='#n1946'>1946</a>
<a id='n1947' href='#n1947'>1947</a>
<a id='n1948' href='#n1948'>1948</a>
<a id='n1949' href='#n1949'>1949</a>
<a id='n1950' href='#n1950'>1950</a>
<a id='n1951' href='#n1951'>1951</a>
<a id='n1952' href='#n1952'>1952</a>
<a id='n1953' href='#n1953'>1953</a>
<a id='n1954' href='#n1954'>1954</a>
<a id='n1955' href='#n1955'>1955</a>
<a id='n1956' href='#n1956'>1956</a>
<a id='n1957' href='#n1957'>1957</a>
<a id='n1958' href='#n1958'>1958</a>
<a id='n1959' href='#n1959'>1959</a>
<a id='n1960' href='#n1960'>1960</a>
<a id='n1961' href='#n1961'>1961</a>
<a id='n1962' href='#n1962'>1962</a>
<a id='n1963' href='#n1963'>1963</a>
<a id='n1964' href='#n1964'>1964</a>
<a id='n1965' href='#n1965'>1965</a>
<a id='n1966' href='#n1966'>1966</a>
<a id='n1967' href='#n1967'>1967</a>
<a id='n1968' href='#n1968'>1968</a>
<a id='n1969' href='#n1969'>1969</a>
<a id='n1970' href='#n1970'>1970</a>
<a id='n1971' href='#n1971'>1971</a>
<a id='n1972' href='#n1972'>1972</a>
<a id='n1973' href='#n1973'>1973</a>
<a id='n1974' href='#n1974'>1974</a>
<a id='n1975' href='#n1975'>1975</a>
<a id='n1976' href='#n1976'>1976</a>
<a id='n1977' href='#n1977'>1977</a>
<a id='n1978' href='#n1978'>1978</a>
<a id='n1979' href='#n1979'>1979</a>
<a id='n1980' href='#n1980'>1980</a>
<a id='n1981' href='#n1981'>1981</a>
<a id='n1982' href='#n1982'>1982</a>
<a id='n1983' href='#n1983'>1983</a>
<a id='n1984' href='#n1984'>1984</a>
<a id='n1985' href='#n1985'>1985</a>
<a id='n1986' href='#n1986'>1986</a>
<a id='n1987' href='#n1987'>1987</a>
<a id='n1988' href='#n1988'>1988</a>
<a id='n1989' href='#n1989'>1989</a>
<a id='n1990' href='#n1990'>1990</a>
<a id='n1991' href='#n1991'>1991</a>
<a id='n1992' href='#n1992'>1992</a>
<a id='n1993' href='#n1993'>1993</a>
<a id='n1994' href='#n1994'>1994</a>
<a id='n1995' href='#n1995'>1995</a>
<a id='n1996' href='#n1996'>1996</a>
<a id='n1997' href='#n1997'>1997</a>
<a id='n1998' href='#n1998'>1998</a>
<a id='n1999' href='#n1999'>1999</a>
<a id='n2000' href='#n2000'>2000</a>
<a id='n2001' href='#n2001'>2001</a>
<a id='n2002' href='#n2002'>2002</a>
<a id='n2003' href='#n2003'>2003</a>
<a id='n2004' href='#n2004'>2004</a>
<a id='n2005' href='#n2005'>2005</a>
<a id='n2006' href='#n2006'>2006</a>
<a id='n2007' href='#n2007'>2007</a>
<a id='n2008' href='#n2008'>2008</a>
<a id='n2009' href='#n2009'>2009</a>
<a id='n2010' href='#n2010'>2010</a>
<a id='n2011' href='#n2011'>2011</a>
<a id='n2012' href='#n2012'>2012</a>
<a id='n2013' href='#n2013'>2013</a>
<a id='n2014' href='#n2014'>2014</a>
<a id='n2015' href='#n2015'>2015</a>
<a id='n2016' href='#n2016'>2016</a>
<a id='n2017' href='#n2017'>2017</a>
<a id='n2018' href='#n2018'>2018</a>
<a id='n2019' href='#n2019'>2019</a>
<a id='n2020' href='#n2020'>2020</a>
<a id='n2021' href='#n2021'>2021</a>
<a id='n2022' href='#n2022'>2022</a>
<a id='n2023' href='#n2023'>2023</a>
<a id='n2024' href='#n2024'>2024</a>
<a id='n2025' href='#n2025'>2025</a>
<a id='n2026' href='#n2026'>2026</a>
<a id='n2027' href='#n2027'>2027</a>
<a id='n2028' href='#n2028'>2028</a>
<a id='n2029' href='#n2029'>2029</a>
<a id='n2030' href='#n2030'>2030</a>
<a id='n2031' href='#n2031'>2031</a>
<a id='n2032' href='#n2032'>2032</a>
<a id='n2033' href='#n2033'>2033</a>
<a id='n2034' href='#n2034'>2034</a>
<a id='n2035' href='#n2035'>2035</a>
<a id='n2036' href='#n2036'>2036</a>
<a id='n2037' href='#n2037'>2037</a>
<a id='n2038' href='#n2038'>2038</a>
<a id='n2039' href='#n2039'>2039</a>
<a id='n2040' href='#n2040'>2040</a>
<a id='n2041' href='#n2041'>2041</a>
<a id='n2042' href='#n2042'>2042</a>
<a id='n2043' href='#n2043'>2043</a>
<a id='n2044' href='#n2044'>2044</a>
<a id='n2045' href='#n2045'>2045</a>
<a id='n2046' href='#n2046'>2046</a>
<a id='n2047' href='#n2047'>2047</a>
<a id='n2048' href='#n2048'>2048</a>
<a id='n2049' href='#n2049'>2049</a>
<a id='n2050' href='#n2050'>2050</a>
<a id='n2051' href='#n2051'>2051</a>
<a id='n2052' href='#n2052'>2052</a>
<a id='n2053' href='#n2053'>2053</a>
<a id='n2054' href='#n2054'>2054</a>
<a id='n2055' href='#n2055'>2055</a>
<a id='n2056' href='#n2056'>2056</a>
<a id='n2057' href='#n2057'>2057</a>
<a id='n2058' href='#n2058'>2058</a>
<a id='n2059' href='#n2059'>2059</a>
<a id='n2060' href='#n2060'>2060</a>
<a id='n2061' href='#n2061'>2061</a>
<a id='n2062' href='#n2062'>2062</a>
<a id='n2063' href='#n2063'>2063</a>
<a id='n2064' href='#n2064'>2064</a>
<a id='n2065' href='#n2065'>2065</a>
<a id='n2066' href='#n2066'>2066</a>
<a id='n2067' href='#n2067'>2067</a>
<a id='n2068' href='#n2068'>2068</a>
<a id='n2069' href='#n2069'>2069</a>
<a id='n2070' href='#n2070'>2070</a>
<a id='n2071' href='#n2071'>2071</a>
<a id='n2072' href='#n2072'>2072</a>
<a id='n2073' href='#n2073'>2073</a>
<a id='n2074' href='#n2074'>2074</a>
<a id='n2075' href='#n2075'>2075</a>
<a id='n2076' href='#n2076'>2076</a>
<a id='n2077' href='#n2077'>2077</a>
<a id='n2078' href='#n2078'>2078</a>
<a id='n2079' href='#n2079'>2079</a>
<a id='n2080' href='#n2080'>2080</a>
<a id='n2081' href='#n2081'>2081</a>
<a id='n2082' href='#n2082'>2082</a>
<a id='n2083' href='#n2083'>2083</a>
<a id='n2084' href='#n2084'>2084</a>
<a id='n2085' href='#n2085'>2085</a>
<a id='n2086' href='#n2086'>2086</a>
<a id='n2087' href='#n2087'>2087</a>
<a id='n2088' href='#n2088'>2088</a>
<a id='n2089' href='#n2089'>2089</a>
<a id='n2090' href='#n2090'>2090</a>
<a id='n2091' href='#n2091'>2091</a>
<a id='n2092' href='#n2092'>2092</a>
<a id='n2093' href='#n2093'>2093</a>
<a id='n2094' href='#n2094'>2094</a>
<a id='n2095' href='#n2095'>2095</a>
<a id='n2096' href='#n2096'>2096</a>
<a id='n2097' href='#n2097'>2097</a>
<a id='n2098' href='#n2098'>2098</a>
<a id='n2099' href='#n2099'>2099</a>
<a id='n2100' href='#n2100'>2100</a>
<a id='n2101' href='#n2101'>2101</a>
<a id='n2102' href='#n2102'>2102</a>
<a id='n2103' href='#n2103'>2103</a>
<a id='n2104' href='#n2104'>2104</a>
<a id='n2105' href='#n2105'>2105</a>
<a id='n2106' href='#n2106'>2106</a>
<a id='n2107' href='#n2107'>2107</a>
<a id='n2108' href='#n2108'>2108</a>
<a id='n2109' href='#n2109'>2109</a>
<a id='n2110' href='#n2110'>2110</a>
<a id='n2111' href='#n2111'>2111</a>
<a id='n2112' href='#n2112'>2112</a>
<a id='n2113' href='#n2113'>2113</a>
<a id='n2114' href='#n2114'>2114</a>
<a id='n2115' href='#n2115'>2115</a>
<a id='n2116' href='#n2116'>2116</a>
<a id='n2117' href='#n2117'>2117</a>
<a id='n2118' href='#n2118'>2118</a>
<a id='n2119' href='#n2119'>2119</a>
<a id='n2120' href='#n2120'>2120</a>
<a id='n2121' href='#n2121'>2121</a>
<a id='n2122' href='#n2122'>2122</a>
<a id='n2123' href='#n2123'>2123</a>
<a id='n2124' href='#n2124'>2124</a>
<a id='n2125' href='#n2125'>2125</a>
<a id='n2126' href='#n2126'>2126</a>
<a id='n2127' href='#n2127'>2127</a>
<a id='n2128' href='#n2128'>2128</a>
<a id='n2129' href='#n2129'>2129</a>
<a id='n2130' href='#n2130'>2130</a>
<a id='n2131' href='#n2131'>2131</a>
<a id='n2132' href='#n2132'>2132</a>
<a id='n2133' href='#n2133'>2133</a>
<a id='n2134' href='#n2134'>2134</a>
<a id='n2135' href='#n2135'>2135</a>
<a id='n2136' href='#n2136'>2136</a>
<a id='n2137' href='#n2137'>2137</a>
<a id='n2138' href='#n2138'>2138</a>
<a id='n2139' href='#n2139'>2139</a>
<a id='n2140' href='#n2140'>2140</a>
<a id='n2141' href='#n2141'>2141</a>
<a id='n2142' href='#n2142'>2142</a>
<a id='n2143' href='#n2143'>2143</a>
<a id='n2144' href='#n2144'>2144</a>
<a id='n2145' href='#n2145'>2145</a>
<a id='n2146' href='#n2146'>2146</a>
<a id='n2147' href='#n2147'>2147</a>
<a id='n2148' href='#n2148'>2148</a>
<a id='n2149' href='#n2149'>2149</a>
<a id='n2150' href='#n2150'>2150</a>
<a id='n2151' href='#n2151'>2151</a>
<a id='n2152' href='#n2152'>2152</a>
<a id='n2153' href='#n2153'>2153</a>
<a id='n2154' href='#n2154'>2154</a>
<a id='n2155' href='#n2155'>2155</a>
<a id='n2156' href='#n2156'>2156</a>
<a id='n2157' href='#n2157'>2157</a>
<a id='n2158' href='#n2158'>2158</a>
<a id='n2159' href='#n2159'>2159</a>
<a id='n2160' href='#n2160'>2160</a>
<a id='n2161' href='#n2161'>2161</a>
<a id='n2162' href='#n2162'>2162</a>
<a id='n2163' href='#n2163'>2163</a>
<a id='n2164' href='#n2164'>2164</a>
<a id='n2165' href='#n2165'>2165</a>
<a id='n2166' href='#n2166'>2166</a>
<a id='n2167' href='#n2167'>2167</a>
<a id='n2168' href='#n2168'>2168</a>
<a id='n2169' href='#n2169'>2169</a>
<a id='n2170' href='#n2170'>2170</a>
<a id='n2171' href='#n2171'>2171</a>
<a id='n2172' href='#n2172'>2172</a>
<a id='n2173' href='#n2173'>2173</a>
<a id='n2174' href='#n2174'>2174</a>
<a id='n2175' href='#n2175'>2175</a>
<a id='n2176' href='#n2176'>2176</a>
<a id='n2177' href='#n2177'>2177</a>
<a id='n2178' href='#n2178'>2178</a>
<a id='n2179' href='#n2179'>2179</a>
<a id='n2180' href='#n2180'>2180</a>
<a id='n2181' href='#n2181'>2181</a>
<a id='n2182' href='#n2182'>2182</a>
<a id='n2183' href='#n2183'>2183</a>
<a id='n2184' href='#n2184'>2184</a>
<a id='n2185' href='#n2185'>2185</a>
<a id='n2186' href='#n2186'>2186</a>
<a id='n2187' href='#n2187'>2187</a>
<a id='n2188' href='#n2188'>2188</a>
<a id='n2189' href='#n2189'>2189</a>
<a id='n2190' href='#n2190'>2190</a>
<a id='n2191' href='#n2191'>2191</a>
<a id='n2192' href='#n2192'>2192</a>
<a id='n2193' href='#n2193'>2193</a>
</pre></td>
<td class='lines'><pre><code>#include &lt;linux/btrfs.h&gt;
#include &lt;linux/capability.h&gt;
#include &lt;linux/cred.h&gt;
#include &lt;linux/mount.h&gt;
#include &lt;linux/fdtable.h&gt;
#include &lt;linux/file.h&gt;
#include &lt;linux/fs.h&gt;
#include &lt;linux/namei.h&gt;
#include &lt;linux/module.h&gt;
#include &lt;linux/kernel.h&gt;
#include &lt;linux/magic.h&gt;
#include &lt;linux/parser.h&gt;
#include &lt;linux/security.h&gt;
#include &lt;linux/seq_file.h&gt;
#include &lt;linux/statfs.h&gt;
#include &lt;linux/slab.h&gt;
#include &lt;linux/user_namespace.h&gt;
#include &lt;linux/uidgid.h&gt;
#include &lt;linux/xattr.h&gt;
#include &lt;linux/posix_acl.h&gt;
#include &lt;linux/posix_acl_xattr.h&gt;
#include &lt;linux/uio.h&gt;
#include &lt;linux/fiemap.h&gt;
#include &lt;linux/pagemap.h&gt;

struct shiftfs_super_info {
	struct vfsmount *mnt;
	struct user_namespace *userns;
	/* creds of process who created the super block */
	const struct cred *creator_cred;
	bool mark;
	unsigned int passthrough;
	unsigned int passthrough_mark;
};

static void shiftfs_fill_inode(struct inode *inode, unsigned long ino,
			       umode_t mode, dev_t dev, struct dentry *dentry);

#define SHIFTFS_PASSTHROUGH_NONE 0
#define SHIFTFS_PASSTHROUGH_STAT 1
#define SHIFTFS_PASSTHROUGH_IOCTL 2
#define SHIFTFS_PASSTHROUGH_ALL                                                \
	(SHIFTFS_PASSTHROUGH_STAT | SHIFTFS_PASSTHROUGH_IOCTL)

static inline bool shiftfs_passthrough_ioctls(struct shiftfs_super_info *info)
{
	if (!(info-&gt;passthrough &amp; SHIFTFS_PASSTHROUGH_IOCTL))
		return false;

	return true;
}

static inline bool shiftfs_passthrough_statfs(struct shiftfs_super_info *info)
{
	if (!(info-&gt;passthrough &amp; SHIFTFS_PASSTHROUGH_STAT))
		return false;

	return true;
}

enum {
	OPT_MARK,
	OPT_PASSTHROUGH,
	OPT_LAST,
};

/* global filesystem options */
static const match_table_t tokens = {
	{ OPT_MARK, "mark" },
	{ OPT_PASSTHROUGH, "passthrough=%u" },
	{ OPT_LAST, NULL }
};

static const struct cred *shiftfs_override_creds(const struct super_block *sb)
{
	struct shiftfs_super_info *sbinfo = sb-&gt;s_fs_info;

	return override_creds(sbinfo-&gt;creator_cred);
}

static inline void shiftfs_revert_object_creds(const struct cred *oldcred,
					       struct cred *newcred)
{
	revert_creds(oldcred);
	put_cred(newcred);
}

static kuid_t shift_kuid(struct user_namespace *from, struct user_namespace *to,
			 kuid_t kuid)
{
	uid_t uid = from_kuid(from, kuid);
	return make_kuid(to, uid);
}

static kgid_t shift_kgid(struct user_namespace *from, struct user_namespace *to,
			 kgid_t kgid)
{
	gid_t gid = from_kgid(from, kgid);
	return make_kgid(to, gid);
}

static int shiftfs_override_object_creds(const struct super_block *sb,
					 const struct cred **oldcred,
					 struct cred **newcred,
					 struct dentry *dentry, umode_t mode,
					 bool hardlink)
{
	struct shiftfs_super_info *sbinfo = sb-&gt;s_fs_info;
	kuid_t fsuid = current_fsuid();
	kgid_t fsgid = current_fsgid();

	*oldcred = shiftfs_override_creds(sb);

	*newcred = prepare_creds();
	if (!*newcred) {
		revert_creds(*oldcred);
		return -ENOMEM;
	}

	(*newcred)-&gt;fsuid = shift_kuid(sb-&gt;s_user_ns, sbinfo-&gt;userns, fsuid);
	(*newcred)-&gt;fsgid = shift_kgid(sb-&gt;s_user_ns, sbinfo-&gt;userns, fsgid);

	if (!hardlink) {
		int err = security_dentry_create_files_as(dentry, mode,
							  &amp;dentry-&gt;d_name,
							  *oldcred, *newcred);
		if (err) {
			shiftfs_revert_object_creds(*oldcred, *newcred);
			return err;
		}
	}

	put_cred(override_creds(*newcred));
	return 0;
}

static void shiftfs_copyattr(struct inode *from, struct inode *to)
{
	struct user_namespace *from_ns = from-&gt;i_sb-&gt;s_user_ns;
	struct user_namespace *to_ns = to-&gt;i_sb-&gt;s_user_ns;

	to-&gt;i_uid = shift_kuid(from_ns, to_ns, from-&gt;i_uid);
	to-&gt;i_gid = shift_kgid(from_ns, to_ns, from-&gt;i_gid);
	to-&gt;i_mode = from-&gt;i_mode;
	to-&gt;i_atime = from-&gt;i_atime;
	to-&gt;i_mtime = from-&gt;i_mtime;
	to-&gt;i_ctime = from-&gt;i_ctime;
	i_size_write(to, i_size_read(from));
}

static void shiftfs_copyflags(struct inode *from, struct inode *to)
{
	unsigned int mask = S_SYNC | S_IMMUTABLE | S_APPEND | S_NOATIME;

	inode_set_flags(to, from-&gt;i_flags &amp; mask, mask);
}

static void shiftfs_file_accessed(struct file *file)
{
	struct inode *upperi, *loweri;

	if (file-&gt;f_flags &amp; O_NOATIME)
		return;

	upperi = file_inode(file);
	loweri = upperi-&gt;i_private;

	if (!loweri)
		return;

	upperi-&gt;i_mtime = loweri-&gt;i_mtime;
	upperi-&gt;i_ctime = loweri-&gt;i_ctime;

	touch_atime(&amp;file-&gt;f_path);
}

static int shiftfs_parse_mount_options(struct shiftfs_super_info *sbinfo,
				       char *options)
{
	char *p;
	substring_t args[MAX_OPT_ARGS];

	sbinfo-&gt;mark = false;
	sbinfo-&gt;passthrough = 0;

	while ((p = strsep(&amp;options, ",")) != NULL) {
		int err, intarg, token;

		if (!*p)
			continue;

		token = match_token(p, tokens, args);
		switch (token) {
		case OPT_MARK:
			sbinfo-&gt;mark = true;
			break;
		case OPT_PASSTHROUGH:
			err = match_int(&amp;args[0], &amp;intarg);
			if (err)
				return err;

			if (intarg &amp; ~SHIFTFS_PASSTHROUGH_ALL)
				return -EINVAL;

			sbinfo-&gt;passthrough = intarg;
			break;
		default:
			return -EINVAL;
		}
	}

	return 0;
}

static void shiftfs_d_release(struct dentry *dentry)
{
	struct dentry *lowerd = dentry-&gt;d_fsdata;

	if (lowerd)
		dput(lowerd);
}

static struct dentry *shiftfs_d_real(struct dentry *dentry,
				     const struct inode *inode)
{
	struct dentry *lowerd = dentry-&gt;d_fsdata;

	if (inode &amp;&amp; d_inode(dentry) == inode)
		return dentry;

	lowerd = d_real(lowerd, inode);
	if (lowerd &amp;&amp; (!inode || inode == d_inode(lowerd)))
		return lowerd;

	WARN(1, "shiftfs_d_real(%pd4, %s:%lu): real dentry not found\n", dentry,
	     inode ? inode-&gt;i_sb-&gt;s_id : "NULL", inode ? inode-&gt;i_ino : 0);
	return dentry;
}

static int shiftfs_d_weak_revalidate(struct dentry *dentry, unsigned int flags)
{
	int err = 1;
	struct dentry *lowerd = dentry-&gt;d_fsdata;

	if (d_is_negative(lowerd) != d_is_negative(dentry))
		return 0;

	if ((lowerd-&gt;d_flags &amp; DCACHE_OP_WEAK_REVALIDATE))
		err = lowerd-&gt;d_op-&gt;d_weak_revalidate(lowerd, flags);

	if (d_really_is_positive(dentry)) {
		struct inode *inode = d_inode(dentry);
		struct inode *loweri = d_inode(lowerd);

		shiftfs_copyattr(loweri, inode);
	}

	return err;
}

static int shiftfs_d_revalidate(struct dentry *dentry, unsigned int flags)
{
	int err = 1;
	struct dentry *lowerd = dentry-&gt;d_fsdata;

	if (d_unhashed(lowerd) ||
	    ((d_is_negative(lowerd) != d_is_negative(dentry))))
		return 0;

	if (flags &amp; LOOKUP_RCU)
		return -ECHILD;

	if ((lowerd-&gt;d_flags &amp; DCACHE_OP_REVALIDATE))
		err = lowerd-&gt;d_op-&gt;d_revalidate(lowerd, flags);

	if (d_really_is_positive(dentry)) {
		struct inode *inode = d_inode(dentry);
		struct inode *loweri = d_inode(lowerd);

		shiftfs_copyattr(loweri, inode);
	}

	return err;
}

static const struct dentry_operations shiftfs_dentry_ops = {
	.d_release	   = shiftfs_d_release,
	.d_real		   = shiftfs_d_real,
	.d_revalidate	   = shiftfs_d_revalidate,
	.d_weak_revalidate = shiftfs_d_weak_revalidate,
};

static const char *shiftfs_get_link(struct dentry *dentry, struct inode *inode,
				    struct delayed_call *done)
{
	const char *p;
	const struct cred *oldcred;
	struct dentry *lowerd;

	/* RCU lookup not supported */
	if (!dentry)
		return ERR_PTR(-ECHILD);

	lowerd = dentry-&gt;d_fsdata;
	oldcred = shiftfs_override_creds(dentry-&gt;d_sb);
	p = vfs_get_link(lowerd, done);
	revert_creds(oldcred);

	return p;
}

static int shiftfs_setxattr(struct dentry *dentry, struct inode *inode,
			    const char *name, const void *value,
			    size_t size, int flags)
{
	struct dentry *lowerd = dentry-&gt;d_fsdata;
	int err;
	const struct cred *oldcred;

	oldcred = shiftfs_override_creds(dentry-&gt;d_sb);
	err = vfs_setxattr(&amp;init_user_ns, lowerd, name, value, size, flags);
	revert_creds(oldcred);

	shiftfs_copyattr(lowerd-&gt;d_inode, inode);

	return err;
}

static int shiftfs_xattr_get(const struct xattr_handler *handler,
			     struct dentry *dentry, struct inode *inode,
			     const char *name, void *value, size_t size)
{
	struct dentry *lowerd = dentry-&gt;d_fsdata;
	int err;
	const struct cred *oldcred;

	oldcred = shiftfs_override_creds(dentry-&gt;d_sb);
	err = vfs_getxattr(&amp;init_user_ns, lowerd, name, value, size);
	revert_creds(oldcred);

	return err;
}

static ssize_t shiftfs_listxattr(struct dentry *dentry, char *list,
				 size_t size)
{
	struct dentry *lowerd = dentry-&gt;d_fsdata;
	int err;
	const struct cred *oldcred;

	oldcred = shiftfs_override_creds(dentry-&gt;d_sb);
	err = vfs_listxattr(lowerd, list, size);
	revert_creds(oldcred);

	return err;
}

static int shiftfs_removexattr(struct user_namespace *ns,
			       struct dentry *dentry, const char *name)
{
	struct dentry *lowerd = dentry-&gt;d_fsdata;
	int err;
	const struct cred *oldcred;

	oldcred = shiftfs_override_creds(dentry-&gt;d_sb);
	err = vfs_removexattr(&amp;init_user_ns, lowerd, name);
	revert_creds(oldcred);

	/* update c/mtime */
	shiftfs_copyattr(lowerd-&gt;d_inode, d_inode(dentry));

	return err;
}

static int shiftfs_xattr_set(const struct xattr_handler *handler,
			     struct user_namespace *ns,
			     struct dentry *dentry, struct inode *inode,
			     const char *name, const void *value, size_t size,
			     int flags)
{
	if (!value)
		return shiftfs_removexattr(&amp;init_user_ns, dentry, name);
	return shiftfs_setxattr(dentry, inode, name, value, size, flags);
}

static int shiftfs_inode_test(struct inode *inode, void *data)
{
	return inode-&gt;i_private == data;
}

static int shiftfs_inode_set(struct inode *inode, void *data)
{
	inode-&gt;i_private = data;
	return 0;
}

static int shiftfs_create_object(struct inode *diri, struct dentry *dentry,
				 umode_t mode, const char *symlink,
				 struct dentry *hardlink, bool excl)
{
	int err;
	const struct cred *oldcred;
	struct cred *newcred;
	void *loweri_iop_ptr = NULL;
	umode_t modei = mode;
	struct super_block *dir_sb = diri-&gt;i_sb;
	struct dentry *lowerd_new = dentry-&gt;d_fsdata;
	struct inode *inode = NULL, *loweri_dir = diri-&gt;i_private;
	const struct inode_operations *loweri_dir_iop = loweri_dir-&gt;i_op;
	struct dentry *lowerd_link = NULL;

	if (hardlink) {
		loweri_iop_ptr = loweri_dir_iop-&gt;link;
	} else {
		switch (mode &amp; S_IFMT) {
		case S_IFDIR:
			loweri_iop_ptr = loweri_dir_iop-&gt;mkdir;
			break;
		case S_IFREG:
			loweri_iop_ptr = loweri_dir_iop-&gt;create;
			break;
		case S_IFLNK:
			loweri_iop_ptr = loweri_dir_iop-&gt;symlink;
			break;
		case S_IFSOCK:
			/* fall through */
		case S_IFIFO:
			loweri_iop_ptr = loweri_dir_iop-&gt;mknod;
			break;
		}
	}
	if (!loweri_iop_ptr) {
		err = -EINVAL;
		goto out_iput;
	}

	inode_lock_nested(loweri_dir, I_MUTEX_PARENT);

	if (!hardlink) {
		inode = new_inode(dir_sb);
		if (!inode) {
			err = -ENOMEM;
			goto out_iput;
		}

		/*
		 * new_inode() will have added the new inode to the super
		 * block's list of inodes. Further below we will call
		 * inode_insert5() Which would perform the same operation again
		 * thereby corrupting the list. To avoid this raise I_CREATING
		 * in i_state which will cause inode_insert5() to skip this
		 * step. I_CREATING will be cleared by d_instantiate_new()
		 * below.
		 */
		spin_lock(&amp;inode-&gt;i_lock);
		inode-&gt;i_state |= I_CREATING;
		spin_unlock(&amp;inode-&gt;i_lock);

		inode_init_owner(&amp;init_user_ns, inode, diri, mode);
		modei = inode-&gt;i_mode;
	}

	err = shiftfs_override_object_creds(dentry-&gt;d_sb, &amp;oldcred, &amp;newcred,
					    dentry, modei, hardlink != NULL);
	if (err)
		goto out_iput;

	if (hardlink) {
		lowerd_link = hardlink-&gt;d_fsdata;
		err = vfs_link(lowerd_link, &amp;init_user_ns, loweri_dir, lowerd_new, NULL);
	} else {
		switch (modei &amp; S_IFMT) {
		case S_IFDIR:
			err = vfs_mkdir(&amp;init_user_ns, loweri_dir, lowerd_new, modei);
			break;
		case S_IFREG:
			err = vfs_create(&amp;init_user_ns, loweri_dir, lowerd_new, modei, excl);
			break;
		case S_IFLNK:
			err = vfs_symlink(&amp;init_user_ns, loweri_dir, lowerd_new, symlink);
			break;
		case S_IFSOCK:
			/* fall through */
		case S_IFIFO:
			err = vfs_mknod(&amp;init_user_ns, loweri_dir, lowerd_new, modei, 0);
			break;
		default:
			err = -EINVAL;
			break;
		}
	}

	shiftfs_revert_object_creds(oldcred, newcred);

	if (!err &amp;&amp; WARN_ON(!lowerd_new-&gt;d_inode))
		err = -EIO;
	if (err)
		goto out_iput;

	if (hardlink) {
		inode = d_inode(hardlink);
		ihold(inode);

		/* copy up times from lower inode */
		shiftfs_copyattr(d_inode(lowerd_link), inode);
		set_nlink(d_inode(hardlink), d_inode(lowerd_link)-&gt;i_nlink);
		d_instantiate(dentry, inode);
	} else {
		struct inode *inode_tmp;
		struct inode *loweri_new = d_inode(lowerd_new);

		inode_tmp = inode_insert5(inode, (unsigned long)loweri_new,
					  shiftfs_inode_test, shiftfs_inode_set,
					  loweri_new);
		if (unlikely(inode_tmp != inode)) {
			pr_err_ratelimited("shiftfs: newly created inode found in cache\n");
			iput(inode_tmp);
			err = -EINVAL;
			goto out_iput;
		}

		ihold(loweri_new);
		shiftfs_fill_inode(inode, loweri_new-&gt;i_ino, loweri_new-&gt;i_mode,
				   0, lowerd_new);
		d_instantiate_new(dentry, inode);
	}

	shiftfs_copyattr(loweri_dir, diri);
	if (loweri_iop_ptr == loweri_dir_iop-&gt;mkdir)
		set_nlink(diri, loweri_dir-&gt;i_nlink);

	inode = NULL;

out_iput:
	iput(inode);
	inode_unlock(loweri_dir);

	return err;
}

static int shiftfs_create(struct user_namespace *ns,
			  struct inode *dir, struct dentry *dentry,
			  umode_t mode,  bool excl)
{
	mode |= S_IFREG;

	return shiftfs_create_object(dir, dentry, mode, NULL, NULL, excl);
}

static int shiftfs_mkdir(struct user_namespace *ns, struct inode *dir, struct dentry *dentry,
			 umode_t mode)
{
	mode |= S_IFDIR;

	return shiftfs_create_object(dir, dentry, mode, NULL, NULL, false);
}

static int shiftfs_link(struct dentry *hardlink, struct inode *dir,
			struct dentry *dentry)
{
	return shiftfs_create_object(dir, dentry, 0, NULL, hardlink, false);
}

static int shiftfs_mknod(struct user_namespace *ns,
			 struct inode *dir, struct dentry *dentry, umode_t mode,
			 dev_t rdev)
{
	if (!S_ISFIFO(mode) &amp;&amp; !S_ISSOCK(mode))
		return -EPERM;

	return shiftfs_create_object(dir, dentry, mode, NULL, NULL, false);
}

static int shiftfs_symlink(struct user_namespace *ns, struct inode *dir, struct dentry *dentry,
			   const char *symlink)
{
	return shiftfs_create_object(dir, dentry, S_IFLNK, symlink, NULL, false);
}

static int shiftfs_rm(struct inode *dir, struct dentry *dentry, bool rmdir)
{
	struct dentry *lowerd = dentry-&gt;d_fsdata;
	struct inode *loweri = dir-&gt;i_private;
	struct inode *inode = d_inode(dentry);
	int err;
	const struct cred *oldcred;

	dget(lowerd);
	oldcred = shiftfs_override_creds(dentry-&gt;d_sb);
	inode_lock_nested(loweri, I_MUTEX_PARENT);
	if (rmdir)
		err = vfs_rmdir(&amp;init_user_ns, loweri, lowerd);
	else
		err = vfs_unlink(&amp;init_user_ns, loweri, lowerd, NULL);
	revert_creds(oldcred);

	if (!err) {
		d_drop(dentry);

		if (rmdir)
			clear_nlink(inode);
		else
			drop_nlink(inode);
	}
	inode_unlock(loweri);

	shiftfs_copyattr(loweri, dir);
	dput(lowerd);

	return err;
}

static int shiftfs_unlink(struct inode *dir, struct dentry *dentry)
{
	return shiftfs_rm(dir, dentry, false);
}

static int shiftfs_rmdir(struct inode *dir, struct dentry *dentry)
{
	return shiftfs_rm(dir, dentry, true);
}

static int shiftfs_rename(struct user_namespace *ns,
			  struct inode *olddir, struct dentry *old,
			  struct inode *newdir, struct dentry *new,
			  unsigned int flags)
{
	struct dentry *lowerd_dir_old = old-&gt;d_parent-&gt;d_fsdata,
		      *lowerd_dir_new = new-&gt;d_parent-&gt;d_fsdata,
		      *lowerd_old = old-&gt;d_fsdata, *lowerd_new = new-&gt;d_fsdata,
		      *trapd;
	struct inode *loweri_dir_old = lowerd_dir_old-&gt;d_inode,
		     *loweri_dir_new = lowerd_dir_new-&gt;d_inode;
	struct renamedata rd = {
		.old_mnt_userns	= ns,
		.old_dir	= loweri_dir_old,
		.old_dentry	= lowerd_old,
		.new_mnt_userns	= ns,
		.new_dir	= loweri_dir_new,
		.new_dentry	= lowerd_new,
	};
	int err = -EINVAL;
	const struct cred *oldcred;

	trapd = lock_rename(lowerd_dir_new, lowerd_dir_old);

	if (trapd == lowerd_old || trapd == lowerd_new)
		goto out_unlock;

	oldcred = shiftfs_override_creds(old-&gt;d_sb);
	err = vfs_rename(&amp;rd);
	revert_creds(oldcred);

	shiftfs_copyattr(loweri_dir_old, olddir);
	shiftfs_copyattr(loweri_dir_new, newdir);

out_unlock:
	unlock_rename(lowerd_dir_new, lowerd_dir_old);

	return err;
}

static struct dentry *shiftfs_lookup(struct inode *dir, struct dentry *dentry,
				     unsigned int flags)
{
	struct dentry *new;
	struct inode *newi;
	const struct cred *oldcred;
	struct dentry *lowerd = dentry-&gt;d_parent-&gt;d_fsdata;
	struct inode *inode = NULL, *loweri = lowerd-&gt;d_inode;

	inode_lock(loweri);
	oldcred = shiftfs_override_creds(dentry-&gt;d_sb);
	new = lookup_one_len(dentry-&gt;d_name.name, lowerd, dentry-&gt;d_name.len);
	revert_creds(oldcred);
	inode_unlock(loweri);

	if (IS_ERR(new))
		return new;

	dentry-&gt;d_fsdata = new;

	newi = new-&gt;d_inode;
	if (!newi)
		goto out;

	inode = iget5_locked(dentry-&gt;d_sb, (unsigned long)newi,
			     shiftfs_inode_test, shiftfs_inode_set, newi);
	if (!inode) {
		dput(new);
		return ERR_PTR(-ENOMEM);
	}
	if (inode-&gt;i_state &amp; I_NEW) {
		/*
		 * inode-&gt;i_private set by shiftfs_inode_set(), but we still
		 * need to take a reference
		*/
		ihold(newi);
		shiftfs_fill_inode(inode, newi-&gt;i_ino, newi-&gt;i_mode, 0, new);
		unlock_new_inode(inode);
	}

out:
	return d_splice_alias(inode, dentry);
}

static int shiftfs_permission(struct user_namespace *ns, struct inode *inode, int mask)
{
	int err;
	const struct cred *oldcred;
	struct inode *loweri = inode-&gt;i_private;

	if (!loweri) {
		WARN_ON(!(mask &amp; MAY_NOT_BLOCK));
		return -ECHILD;
	}

	err = generic_permission(&amp;init_user_ns, inode, mask);
	if (err)
		return err;

	oldcred = shiftfs_override_creds(inode-&gt;i_sb);
	err = inode_permission(&amp;init_user_ns, loweri, mask);
	revert_creds(oldcred);

	return err;
}

static int shiftfs_fiemap(struct inode *inode,
			  struct fiemap_extent_info *fieinfo, u64 start,
			  u64 len)
{
	int err;
	const struct cred *oldcred;
	struct inode *loweri = inode-&gt;i_private;

	if (!loweri-&gt;i_op-&gt;fiemap)
		return -EOPNOTSUPP;

	oldcred = shiftfs_override_creds(inode-&gt;i_sb);
	if (fieinfo-&gt;fi_flags &amp; FIEMAP_FLAG_SYNC)
		filemap_write_and_wait(loweri-&gt;i_mapping);
	err = loweri-&gt;i_op-&gt;fiemap(loweri, fieinfo, start, len);
	revert_creds(oldcred);

	return err;
}

static int shiftfs_tmpfile(struct user_namespace *ns,
			   struct inode *dir, struct file *file,
			   umode_t mode)
{
	int err;
	const struct cred *oldcred;
	struct inode *loweri = dir-&gt;i_private;

	if (!loweri-&gt;i_op-&gt;tmpfile)
		return -EOPNOTSUPP;

	oldcred = shiftfs_override_creds(dir-&gt;i_sb);
	err = loweri-&gt;i_op-&gt;tmpfile(&amp;init_user_ns, loweri, file, mode);
	revert_creds(oldcred);

	return err;
}

static int shiftfs_setattr(struct user_namespace *ns, struct dentry *dentry, struct iattr *attr)
{
	struct dentry *lowerd = dentry-&gt;d_fsdata;
	struct inode *loweri = lowerd-&gt;d_inode;
	struct iattr newattr;
	const struct cred *oldcred;
	struct super_block *sb = dentry-&gt;d_sb;
	struct shiftfs_super_info *sbinfo = sb-&gt;s_fs_info;
	int err;

	err = setattr_prepare(&amp;init_user_ns, dentry, attr);
	if (err)
		return err;

	newattr = *attr;
	newattr.ia_uid = shift_kuid(sb-&gt;s_user_ns, sbinfo-&gt;userns, attr-&gt;ia_uid);
	newattr.ia_gid = shift_kgid(sb-&gt;s_user_ns, sbinfo-&gt;userns, attr-&gt;ia_gid);

	/*
	 * mode change is for clearing setuid/setgid bits. Allow lower fs
	 * to interpret this in its own way.
	 */
	if (newattr.ia_valid &amp; (ATTR_KILL_SUID|ATTR_KILL_SGID))
		newattr.ia_valid &amp;= ~ATTR_MODE;

	inode_lock(loweri);
	oldcred = shiftfs_override_creds(dentry-&gt;d_sb);
	err = notify_change(&amp;init_user_ns, lowerd, &amp;newattr, NULL);
	revert_creds(oldcred);
	inode_unlock(loweri);

	shiftfs_copyattr(loweri, d_inode(dentry));

	return err;
}

static int shiftfs_getattr(struct user_namespace *ns,
			   const struct path *path, struct kstat *stat,
			   u32 request_mask, unsigned int query_flags)
{
	struct inode *inode = path-&gt;dentry-&gt;d_inode;
	struct dentry *lowerd = path-&gt;dentry-&gt;d_fsdata;
	struct inode *loweri = lowerd-&gt;d_inode;
	struct shiftfs_super_info *info = path-&gt;dentry-&gt;d_sb-&gt;s_fs_info;
	struct path newpath = { .mnt = info-&gt;mnt, .dentry = lowerd };
	struct user_namespace *from_ns = loweri-&gt;i_sb-&gt;s_user_ns;
	struct user_namespace *to_ns = inode-&gt;i_sb-&gt;s_user_ns;
	const struct cred *oldcred;
	int err;

	oldcred = shiftfs_override_creds(inode-&gt;i_sb);
	err = vfs_getattr(&amp;newpath, stat, request_mask, query_flags);
	revert_creds(oldcred);

	if (err)
		return err;

	/* transform the underlying id */
	stat-&gt;uid = shift_kuid(from_ns, to_ns, stat-&gt;uid);
	stat-&gt;gid = shift_kgid(from_ns, to_ns, stat-&gt;gid);
	return 0;
}

#ifdef CONFIG_SHIFT_FS_POSIX_ACL

static int
shift_acl_ids(struct user_namespace *from, struct user_namespace *to,
	      struct posix_acl *acl)
{
	int i;

	for (i = 0; i &lt; acl-&gt;a_count; i++) {
		struct posix_acl_entry *e = &amp;acl-&gt;a_entries[i];
		switch(e-&gt;e_tag) {
		case ACL_USER:
			e-&gt;e_uid = shift_kuid(from, to, e-&gt;e_uid);
			if (!uid_valid(e-&gt;e_uid))
				return -EOVERFLOW;
			break;
		case ACL_GROUP:
			e-&gt;e_gid = shift_kgid(from, to, e-&gt;e_gid);
			if (!gid_valid(e-&gt;e_gid))
				return -EOVERFLOW;
			break;
		}
	}
	return 0;
}

static void
shift_acl_xattr_ids(struct user_namespace *from, struct user_namespace *to,
		    void *value, size_t size)
{
	struct posix_acl_xattr_header *header = value;
	struct posix_acl_xattr_entry *entry = (void *)(header + 1), *end;
	int count;
	kuid_t kuid;
	kgid_t kgid;

	if (!value)
		return;
	if (size &lt; sizeof(struct posix_acl_xattr_header))
		return;
	if (header-&gt;a_version != cpu_to_le32(POSIX_ACL_XATTR_VERSION))
		return;

	count = posix_acl_xattr_count(size);
	if (count &lt; 0)
		return;
	if (count == 0)
		return;

	for (end = entry + count; entry != end; entry++) {
		switch(le16_to_cpu(entry-&gt;e_tag)) {
		case ACL_USER:
			kuid = make_kuid(&amp;init_user_ns, le32_to_cpu(entry-&gt;e_id));
			kuid = shift_kuid(from, to, kuid);
			entry-&gt;e_id = cpu_to_le32(from_kuid(&amp;init_user_ns, kuid));
			break;
		case ACL_GROUP:
			kgid = make_kgid(from, le32_to_cpu(entry-&gt;e_id));
			kgid = shift_kgid(from, to, kgid);
			entry-&gt;e_id = cpu_to_le32(from_kgid(from, kgid));
			break;
		default:
			break;
		}
	}
}

static struct posix_acl *
shiftfs_get_acl(struct inode *inode, int type, bool rcu)
{
	struct inode *loweri = inode-&gt;i_private;
	const struct cred *oldcred;
	struct posix_acl *lower_acl, *acl = NULL;
	struct user_namespace *from_ns = loweri-&gt;i_sb-&gt;s_user_ns;
	struct user_namespace *to_ns = inode-&gt;i_sb-&gt;s_user_ns;
	int size;
	int err;

	if (rcu)
		return ERR_PTR(-ECHILD);

	if (!IS_POSIXACL(loweri))
		return NULL;

	oldcred = shiftfs_override_creds(inode-&gt;i_sb);
	lower_acl = get_acl(loweri, type);
	revert_creds(oldcred);

	if (lower_acl &amp;&amp; !IS_ERR(lower_acl)) {
		/* XXX: export posix_acl_clone? */
		size = sizeof(struct posix_acl) +
		       lower_acl-&gt;a_count * sizeof(struct posix_acl_entry);
		acl = kmemdup(lower_acl, size, GFP_KERNEL);
		posix_acl_release(lower_acl);

		if (!acl)
			return ERR_PTR(-ENOMEM);

		refcount_set(&amp;acl-&gt;a_refcount, 1);

		err = shift_acl_ids(from_ns, to_ns, acl);
		if (err) {
			kfree(acl);
			return ERR_PTR(err);
		}
	}

	return acl;
}

static int
shiftfs_posix_acl_xattr_get(const struct xattr_handler *handler,
			   struct dentry *dentry, struct inode *inode,
			   const char *name, void *buffer, size_t size)
{
	struct inode *loweri = inode-&gt;i_private;
	int ret;

	ret = shiftfs_xattr_get(NULL, dentry, inode, handler-&gt;name,
				buffer, size);
	if (ret &lt; 0)
		return ret;

	inode_lock(loweri);
	shift_acl_xattr_ids(loweri-&gt;i_sb-&gt;s_user_ns, inode-&gt;i_sb-&gt;s_user_ns,
			    buffer, size);
	inode_unlock(loweri);
	return ret;
}

static int
shiftfs_posix_acl_xattr_set(const struct xattr_handler *handler,
			    struct user_namespace *ns,
			    struct dentry *dentry, struct inode *inode,
			    const char *name, const void *value,
			    size_t size, int flags)
{
	struct inode *loweri = inode-&gt;i_private;
	int err;

	if (!IS_POSIXACL(loweri) || !loweri-&gt;i_op-&gt;set_acl)
		return -EOPNOTSUPP;
	if (handler-&gt;flags == ACL_TYPE_DEFAULT &amp;&amp; !S_ISDIR(inode-&gt;i_mode))
		return value ? -EACCES : 0;
	if (!inode_owner_or_capable(ns, inode))
		return -EPERM;

	if (value) {
		shift_acl_xattr_ids(inode-&gt;i_sb-&gt;s_user_ns,
				    loweri-&gt;i_sb-&gt;s_user_ns,
				    (void *)value, size);
		err = shiftfs_setxattr(dentry, inode, handler-&gt;name, value,
				       size, flags);
	} else {
		err = shiftfs_removexattr(&amp;init_user_ns, dentry, handler-&gt;name);
	}

	if (!err)
		shiftfs_copyattr(loweri, inode);

	return err;
}

static const struct xattr_handler
shiftfs_posix_acl_access_xattr_handler = {
	.name = XATTR_NAME_POSIX_ACL_ACCESS,
	.flags = ACL_TYPE_ACCESS,
	.get = shiftfs_posix_acl_xattr_get,
	.set = shiftfs_posix_acl_xattr_set,
};

static const struct xattr_handler
shiftfs_posix_acl_default_xattr_handler = {
	.name = XATTR_NAME_POSIX_ACL_DEFAULT,
	.flags = ACL_TYPE_DEFAULT,
	.get = shiftfs_posix_acl_xattr_get,
	.set = shiftfs_posix_acl_xattr_set,
};

#else /* !CONFIG_SHIFT_FS_POSIX_ACL */

#define shiftfs_get_acl NULL

#endif /* CONFIG_SHIFT_FS_POSIX_ACL */

static const struct inode_operations shiftfs_dir_inode_operations = {
	.lookup		= shiftfs_lookup,
	.mkdir		= shiftfs_mkdir,
	.symlink	= shiftfs_symlink,
	.unlink		= shiftfs_unlink,
	.rmdir		= shiftfs_rmdir,
	.rename		= shiftfs_rename,
	.link		= shiftfs_link,
	.setattr	= shiftfs_setattr,
	.create		= shiftfs_create,
	.mknod		= shiftfs_mknod,
	.permission	= shiftfs_permission,
	.getattr	= shiftfs_getattr,
	.listxattr	= shiftfs_listxattr,
	.get_acl	= shiftfs_get_acl,
};

static const struct inode_operations shiftfs_file_inode_operations = {
	.fiemap		= shiftfs_fiemap,
	.getattr	= shiftfs_getattr,
	.get_acl	= shiftfs_get_acl,
	.listxattr	= shiftfs_listxattr,
	.permission	= shiftfs_permission,
	.setattr	= shiftfs_setattr,
	.tmpfile	= shiftfs_tmpfile,
};

static const struct inode_operations shiftfs_special_inode_operations = {
	.getattr	= shiftfs_getattr,
	.get_acl	= shiftfs_get_acl,
	.listxattr	= shiftfs_listxattr,
	.permission	= shiftfs_permission,
	.setattr	= shiftfs_setattr,
};

static const struct inode_operations shiftfs_symlink_inode_operations = {
	.getattr	= shiftfs_getattr,
	.get_link	= shiftfs_get_link,
	.listxattr	= shiftfs_listxattr,
	.setattr	= shiftfs_setattr,
};

static struct file *shiftfs_open_realfile(const struct file *file,
					  struct inode *realinode)
{
	struct file *realfile;
	const struct cred *old_cred;
	struct inode *inode = file_inode(file);
	struct dentry *lowerd = file-&gt;f_path.dentry-&gt;d_fsdata;
	struct shiftfs_super_info *info = inode-&gt;i_sb-&gt;s_fs_info;
	struct path realpath = { .mnt = info-&gt;mnt, .dentry = lowerd };

	old_cred = shiftfs_override_creds(inode-&gt;i_sb);
	realfile = open_with_fake_path(&amp;realpath, file-&gt;f_flags, realinode,
				       info-&gt;creator_cred);
	revert_creds(old_cred);

	return realfile;
}

#define SHIFTFS_SETFL_MASK (O_APPEND | O_NONBLOCK | O_NDELAY | O_DIRECT)

static int shiftfs_change_flags(struct file *file, unsigned int flags)
{
	struct inode *inode = file_inode(file);
	int err;

	/* if some flag changed that cannot be changed then something's amiss */
	if (WARN_ON((file-&gt;f_flags ^ flags) &amp; ~SHIFTFS_SETFL_MASK))
		return -EIO;

	flags &amp;= SHIFTFS_SETFL_MASK;

	if (((flags ^ file-&gt;f_flags) &amp; O_APPEND) &amp;&amp; IS_APPEND(inode))
		return -EPERM;

	if (flags &amp; O_DIRECT) {
		if (!file-&gt;f_mapping-&gt;a_ops ||
		    !file-&gt;f_mapping-&gt;a_ops-&gt;direct_IO)
			return -EINVAL;
	}

	if (file-&gt;f_op-&gt;check_flags) {
		err = file-&gt;f_op-&gt;check_flags(flags);
		if (err)
			return err;
	}

	spin_lock(&amp;file-&gt;f_lock);
	file-&gt;f_flags = (file-&gt;f_flags &amp; ~SHIFTFS_SETFL_MASK) | flags;
	spin_unlock(&amp;file-&gt;f_lock);

	return 0;
}

static int shiftfs_open(struct inode *inode, struct file *file)
{
	struct file *realfile;

	realfile = shiftfs_open_realfile(file, inode-&gt;i_private);
	if (IS_ERR(realfile))
		return PTR_ERR(realfile);

	file-&gt;private_data = realfile;
	/* For O_DIRECT dentry_open() checks f_mapping-&gt;a_ops-&gt;direct_IO. */
	file-&gt;f_mapping = realfile-&gt;f_mapping;

	return 0;
}

static int shiftfs_dir_open(struct inode *inode, struct file *file)
{
	struct file *realfile;
	const struct cred *oldcred;
	struct dentry *lowerd = file-&gt;f_path.dentry-&gt;d_fsdata;
	struct shiftfs_super_info *info = inode-&gt;i_sb-&gt;s_fs_info;
	struct path realpath = { .mnt = info-&gt;mnt, .dentry = lowerd };

	oldcred = shiftfs_override_creds(file-&gt;f_path.dentry-&gt;d_sb);
	realfile = dentry_open(&amp;realpath, file-&gt;f_flags | O_NOATIME,
			       info-&gt;creator_cred);
	revert_creds(oldcred);
	if (IS_ERR(realfile))
		return PTR_ERR(realfile);

	file-&gt;private_data = realfile;

	return 0;
}

static int shiftfs_release(struct inode *inode, struct file *file)
{
	struct file *realfile = file-&gt;private_data;

	if (realfile)
		fput(realfile);

	return 0;
}

static int shiftfs_dir_release(struct inode *inode, struct file *file)
{
	return shiftfs_release(inode, file);
}

static loff_t shiftfs_dir_llseek(struct file *file, loff_t offset, int whence)
{
	struct file *realfile = file-&gt;private_data;

	return vfs_llseek(realfile, offset, whence);
}

static loff_t shiftfs_file_llseek(struct file *file, loff_t offset, int whence)
{
	struct inode *realinode = file_inode(file)-&gt;i_private;

	return generic_file_llseek_size(file, offset, whence,
					realinode-&gt;i_sb-&gt;s_maxbytes,
					i_size_read(realinode));
}

/* XXX: Need to figure out what to to about atime updates, maybe other
 * timestamps too ... ref. ovl_file_accessed() */

static rwf_t shiftfs_iocb_to_rwf(struct kiocb *iocb)
{
	int ifl = iocb-&gt;ki_flags;
	rwf_t flags = 0;

	if (ifl &amp; IOCB_NOWAIT)
		flags |= RWF_NOWAIT;
	if (ifl &amp; IOCB_HIPRI)
		flags |= RWF_HIPRI;
	if (ifl &amp; IOCB_DSYNC)
		flags |= RWF_DSYNC;
	if (ifl &amp; IOCB_SYNC)
		flags |= RWF_SYNC;

	return flags;
}

static int shiftfs_real_fdget(const struct file *file, struct fd *lowerfd)
{
	struct file *realfile;

	if (file-&gt;f_op-&gt;open != shiftfs_open &amp;&amp;
	    file-&gt;f_op-&gt;open != shiftfs_dir_open)
		return -EINVAL;

	realfile = file-&gt;private_data;
	lowerfd-&gt;flags = 0;
	lowerfd-&gt;file = realfile;

	/* Did the flags change since open? */
	if (unlikely(file-&gt;f_flags &amp; ~lowerfd-&gt;file-&gt;f_flags))
		return shiftfs_change_flags(lowerfd-&gt;file, file-&gt;f_flags);

	return 0;
}

static ssize_t shiftfs_read_iter(struct kiocb *iocb, struct iov_iter *iter)
{
	struct file *file = iocb-&gt;ki_filp;
	struct fd lowerfd;
	const struct cred *oldcred;
	ssize_t ret;

	if (!iov_iter_count(iter))
		return 0;

	ret = shiftfs_real_fdget(file, &amp;lowerfd);
	if (ret)
		return ret;

	oldcred = shiftfs_override_creds(file-&gt;f_path.dentry-&gt;d_sb);
	ret = vfs_iter_read(lowerfd.file, iter, &amp;iocb-&gt;ki_pos,
			    shiftfs_iocb_to_rwf(iocb));
	revert_creds(oldcred);

	shiftfs_file_accessed(file);

	fdput(lowerfd);
	return ret;
}

static ssize_t shiftfs_write_iter(struct kiocb *iocb, struct iov_iter *iter)
{
	struct file *file = iocb-&gt;ki_filp;
	struct inode *inode = file_inode(file);
	struct fd lowerfd;
	const struct cred *oldcred;
	ssize_t ret;

	if (!iov_iter_count(iter))
		return 0;

	inode_lock(inode);
	/* Update mode */
	shiftfs_copyattr(inode-&gt;i_private, inode);
	ret = file_remove_privs(file);
	if (ret)
		goto out_unlock;

	ret = shiftfs_real_fdget(file, &amp;lowerfd);
	if (ret)
		goto out_unlock;

	oldcred = shiftfs_override_creds(file-&gt;f_path.dentry-&gt;d_sb);
	file_start_write(lowerfd.file);
	ret = vfs_iter_write(lowerfd.file, iter, &amp;iocb-&gt;ki_pos,
			     shiftfs_iocb_to_rwf(iocb));
	file_end_write(lowerfd.file);
	revert_creds(oldcred);

	/* Update size */
	shiftfs_copyattr(inode-&gt;i_private, inode);

	fdput(lowerfd);

out_unlock:
	inode_unlock(inode);
	return ret;
}

static int shiftfs_fsync(struct file *file, loff_t start, loff_t end,
			 int datasync)
{
	struct fd lowerfd;
	const struct cred *oldcred;
	int ret;

	ret = shiftfs_real_fdget(file, &amp;lowerfd);
	if (ret)
		return ret;

	oldcred = shiftfs_override_creds(file-&gt;f_path.dentry-&gt;d_sb);
	ret = vfs_fsync_range(lowerfd.file, start, end, datasync);
	revert_creds(oldcred);

	fdput(lowerfd);
	return ret;
}

static int shiftfs_mmap(struct file *file, struct vm_area_struct *vma)
{
	struct file *realfile = file-&gt;private_data;
	const struct cred *oldcred;
	int ret;

	if (!realfile-&gt;f_op-&gt;mmap)
		return -ENODEV;

	if (WARN_ON(file != vma-&gt;vm_file))
		return -EIO;

	oldcred = shiftfs_override_creds(file-&gt;f_path.dentry-&gt;d_sb);
	vma-&gt;vm_file = get_file(realfile);
	ret = call_mmap(vma-&gt;vm_file, vma);
	revert_creds(oldcred);

	shiftfs_file_accessed(file);

	if (ret) {
		/*
		 * Drop refcount from new vm_file value and restore original
		 * vm_file value
		 */
		vma-&gt;vm_file = file;
		fput(realfile);
	} else {
		/* Drop refcount from previous vm_file value */
		fput(file);
	}

	return ret;
}

static long shiftfs_fallocate(struct file *file, int mode, loff_t offset,
			      loff_t len)
{
	struct inode *inode = file_inode(file);
	struct inode *loweri = inode-&gt;i_private;
	struct fd lowerfd;
	const struct cred *oldcred;
	int ret;

	ret = shiftfs_real_fdget(file, &amp;lowerfd);
	if (ret)
		return ret;

	oldcred = shiftfs_override_creds(file-&gt;f_path.dentry-&gt;d_sb);
	ret = vfs_fallocate(lowerfd.file, mode, offset, len);
	revert_creds(oldcred);

	/* Update size */
	shiftfs_copyattr(loweri, inode);

	fdput(lowerfd);
	return ret;
}

static int shiftfs_fadvise(struct file *file, loff_t offset, loff_t len,
			   int advice)
{
	struct fd lowerfd;
	const struct cred *oldcred;
	int ret;

	ret = shiftfs_real_fdget(file, &amp;lowerfd);
	if (ret)
		return ret;

	oldcred = shiftfs_override_creds(file-&gt;f_path.dentry-&gt;d_sb);
	ret = vfs_fadvise(lowerfd.file, offset, len, advice);
	revert_creds(oldcred);

	fdput(lowerfd);
	return ret;
}

static int shiftfs_override_ioctl_creds(int cmd, const struct super_block *sb,
					const struct cred **oldcred,
					struct cred **newcred)
{
	struct shiftfs_super_info *sbinfo = sb-&gt;s_fs_info;
	kuid_t fsuid = current_fsuid();
	kgid_t fsgid = current_fsgid();

	*oldcred = shiftfs_override_creds(sb);

	*newcred = prepare_creds();
	if (!*newcred) {
		revert_creds(*oldcred);
		return -ENOMEM;
	}

	(*newcred)-&gt;fsuid = shift_kuid(sb-&gt;s_user_ns, sbinfo-&gt;userns, fsuid);
	(*newcred)-&gt;fsgid = shift_kgid(sb-&gt;s_user_ns, sbinfo-&gt;userns, fsgid);

	/* clear all caps to prevent bypassing capable() checks */
	cap_clear((*newcred)-&gt;cap_bset);
	cap_clear((*newcred)-&gt;cap_effective);
	cap_clear((*newcred)-&gt;cap_inheritable);
	cap_clear((*newcred)-&gt;cap_permitted);

	if (cmd == BTRFS_IOC_SNAP_DESTROY) {
		kuid_t kuid_root = make_kuid(sb-&gt;s_user_ns, 0);
		/*
		 * Allow the root user in the container to remove subvolumes
		 * from other users.
		 */
		if (uid_valid(kuid_root) &amp;&amp; uid_eq(fsuid, kuid_root))
			cap_raise((*newcred)-&gt;cap_effective, CAP_DAC_OVERRIDE);
	}

	put_cred(override_creds(*newcred));
	return 0;
}

static inline void shiftfs_revert_ioctl_creds(const struct cred *oldcred,
					      struct cred *newcred)
{
	return shiftfs_revert_object_creds(oldcred, newcred);
}

static inline bool is_btrfs_snap_ioctl(int cmd)
{
	if ((cmd == BTRFS_IOC_SNAP_CREATE) || (cmd == BTRFS_IOC_SNAP_CREATE_V2))
		return true;

	return false;
}

static int shiftfs_btrfs_ioctl_fd_restore(int cmd, int fd, void __user *arg,
					  struct btrfs_ioctl_vol_args *v1,
					  struct btrfs_ioctl_vol_args_v2 *v2)
{
	int ret;

	if (!is_btrfs_snap_ioctl(cmd))
		return 0;

	if (cmd == BTRFS_IOC_SNAP_CREATE)
		ret = copy_to_user(arg, v1, sizeof(*v1));
	else
		ret = copy_to_user(arg, v2, sizeof(*v2));

	close_fd(fd);
	kfree(v1);
	kfree(v2);

	return ret ? -EFAULT: 0;
}

static int shiftfs_btrfs_ioctl_fd_replace(int cmd, void __user *arg,
					  struct btrfs_ioctl_vol_args **b1,
					  struct btrfs_ioctl_vol_args_v2 **b2,
					  int *newfd)
{
	int oldfd, ret;
	struct fd src;
	struct fd lfd = {};
	struct btrfs_ioctl_vol_args *v1 = NULL;
	struct btrfs_ioctl_vol_args_v2 *v2 = NULL;

	*b1 = NULL;
	*b2 = NULL;

	if (!is_btrfs_snap_ioctl(cmd))
		return 0;

	if (cmd == BTRFS_IOC_SNAP_CREATE) {
		v1 = memdup_user(arg, sizeof(*v1));
		if (IS_ERR(v1))
			return PTR_ERR(v1);
		oldfd = v1-&gt;fd;
	} else {
		v2 = memdup_user(arg, sizeof(*v2));
		if (IS_ERR(v2))
			return PTR_ERR(v2);
		oldfd = v2-&gt;fd;
	}

	src = fdget(oldfd);
	if (!src.file) {
		ret = -EINVAL;
		goto err_free;
	}

	ret = shiftfs_real_fdget(src.file, &amp;lfd);
	if (ret) {
		fdput(src);
		goto err_free;
	}

	/*
	 * shiftfs_real_fdget() does not take a reference to lfd.file, so
	 * take a reference here to offset the one which will be put by
	 * close_fd(), and make sure that reference is put on fdput(lfd).
	 */
	get_file(lfd.file);
	lfd.flags |= FDPUT_FPUT;
	fdput(src);

	*newfd = get_unused_fd_flags(lfd.file-&gt;f_flags);
	if (*newfd &lt; 0) {
		fdput(lfd);
		ret = *newfd;
		goto err_free;
	}

	fd_install(*newfd, lfd.file);

	if (cmd == BTRFS_IOC_SNAP_CREATE) {
		v1-&gt;fd = *newfd;
		ret = copy_to_user(arg, v1, sizeof(*v1));
		v1-&gt;fd = oldfd;
	} else {
		v2-&gt;fd = *newfd;
		ret = copy_to_user(arg, v2, sizeof(*v2));
		v2-&gt;fd = oldfd;
	}

	if (!ret) {
		*b1 = v1;
		*b2 = v2;
	} else {
		shiftfs_btrfs_ioctl_fd_restore(cmd, *newfd, arg, v1, v2);
		ret = -EFAULT;
	}

	return ret;

err_free:
	kfree(v1);
	kfree(v2);

	return ret;
}

static long shiftfs_real_ioctl(struct file *file, unsigned int cmd,
			       unsigned long arg)
{
	struct fd lowerfd;
	struct cred *newcred;
	const struct cred *oldcred;
	int newfd = -EBADF;
	long err = 0, ret = 0;
	void __user *argp = (void __user *)arg;
	struct super_block *sb = file-&gt;f_path.dentry-&gt;d_sb;
	struct btrfs_ioctl_vol_args *btrfs_v1 = NULL;
	struct btrfs_ioctl_vol_args_v2 *btrfs_v2 = NULL;

	ret = shiftfs_btrfs_ioctl_fd_replace(cmd, argp, &amp;btrfs_v1, &amp;btrfs_v2,
					     &amp;newfd);
	if (ret &lt; 0)
		return ret;

	ret = shiftfs_real_fdget(file, &amp;lowerfd);
	if (ret)
		goto out_restore;

	ret = shiftfs_override_ioctl_creds(cmd, sb, &amp;oldcred, &amp;newcred);
	if (ret)
		goto out_fdput;

	ret = vfs_ioctl(lowerfd.file, cmd, arg);

	shiftfs_revert_ioctl_creds(oldcred, newcred);

	shiftfs_copyattr(file_inode(lowerfd.file), file_inode(file));
	shiftfs_copyflags(file_inode(lowerfd.file), file_inode(file));

out_fdput:
	fdput(lowerfd);

out_restore:
	err = shiftfs_btrfs_ioctl_fd_restore(cmd, newfd, argp,
					     btrfs_v1, btrfs_v2);
	if (!ret)
		ret = err;

	return ret;
}

static bool in_ioctl_whitelist(int flag, unsigned long arg)
{
	void __user *argp = (void __user *)arg;
	u64 flags = 0;

	switch (flag) {
	case BTRFS_IOC_FS_INFO:
		return true;
	case BTRFS_IOC_SNAP_CREATE:
		return true;
	case BTRFS_IOC_SNAP_CREATE_V2:
		return true;
	case BTRFS_IOC_SUBVOL_CREATE:
		return true;
	case BTRFS_IOC_SUBVOL_CREATE_V2:
		return true;
	case BTRFS_IOC_SUBVOL_GETFLAGS:
		return true;
	case BTRFS_IOC_SUBVOL_SETFLAGS:
		if (copy_from_user(&amp;flags, argp, sizeof(flags)))
			return false;

		if (flags &amp; ~BTRFS_SUBVOL_RDONLY)
			return false;

		return true;
	case BTRFS_IOC_SNAP_DESTROY:
		return true;
	}

	return false;
}

static long shiftfs_ioctl(struct file *file, unsigned int cmd,
			  unsigned long arg)
{
	switch (cmd) {
	case FS_IOC_GETVERSION:
		/* fall through */
	case FS_IOC_GETFLAGS:
		/* fall through */
	case FS_IOC_SETFLAGS:
		break;
	default:
		if (!in_ioctl_whitelist(cmd, arg) ||
		    !shiftfs_passthrough_ioctls(file-&gt;f_path.dentry-&gt;d_sb-&gt;s_fs_info))
			return -ENOTTY;
	}

	return shiftfs_real_ioctl(file, cmd, arg);
}

static long shiftfs_compat_ioctl(struct file *file, unsigned int cmd,
				 unsigned long arg)
{
	switch (cmd) {
	case FS_IOC32_GETVERSION:
		/* fall through */
	case FS_IOC32_GETFLAGS:
		/* fall through */
	case FS_IOC32_SETFLAGS:
		break;
	default:
		if (!in_ioctl_whitelist(cmd, arg) ||
		    !shiftfs_passthrough_ioctls(file-&gt;f_path.dentry-&gt;d_sb-&gt;s_fs_info))
			return -ENOIOCTLCMD;
	}

	return shiftfs_real_ioctl(file, cmd, arg);
}

enum shiftfs_copyop {
	SHIFTFS_COPY,
	SHIFTFS_CLONE,
	SHIFTFS_DEDUPE,
};

static ssize_t shiftfs_copyfile(struct file *file_in, loff_t pos_in,
				struct file *file_out, loff_t pos_out, u64 len,
				unsigned int flags, enum shiftfs_copyop op)
{
	ssize_t ret;
	struct fd real_in, real_out;
	const struct cred *oldcred;
	struct inode *inode_out = file_inode(file_out);
	struct inode *loweri = inode_out-&gt;i_private;

	ret = shiftfs_real_fdget(file_out, &amp;real_out);
	if (ret)
		return ret;

	ret = shiftfs_real_fdget(file_in, &amp;real_in);
	if (ret) {
		fdput(real_out);
		return ret;
	}

	oldcred = shiftfs_override_creds(inode_out-&gt;i_sb);
	switch (op) {
	case SHIFTFS_COPY:
		ret = vfs_copy_file_range(real_in.file, pos_in, real_out.file,
					  pos_out, len, flags);
		break;

	case SHIFTFS_CLONE:
		ret = vfs_clone_file_range(real_in.file, pos_in, real_out.file,
					   pos_out, len, flags);
		break;

	case SHIFTFS_DEDUPE:
		ret = vfs_dedupe_file_range_one(real_in.file, pos_in,
						real_out.file, pos_out, len,
						flags);
		break;
	}
	revert_creds(oldcred);

	/* Update size */
	shiftfs_copyattr(loweri, inode_out);

	fdput(real_in);
	fdput(real_out);

	return ret;
}

static ssize_t shiftfs_copy_file_range(struct file *file_in, loff_t pos_in,
				       struct file *file_out, loff_t pos_out,
				       size_t len, unsigned int flags)
{
	return shiftfs_copyfile(file_in, pos_in, file_out, pos_out, len, flags,
				SHIFTFS_COPY);
}

static loff_t shiftfs_remap_file_range(struct file *file_in, loff_t pos_in,
				       struct file *file_out, loff_t pos_out,
				       loff_t len, unsigned int remap_flags)
{
	enum shiftfs_copyop op;

	if (remap_flags &amp; ~(REMAP_FILE_DEDUP | REMAP_FILE_ADVISORY))
		return -EINVAL;

	if (remap_flags &amp; REMAP_FILE_DEDUP)
		op = SHIFTFS_DEDUPE;
	else
		op = SHIFTFS_CLONE;

	return shiftfs_copyfile(file_in, pos_in, file_out, pos_out, len,
				remap_flags, op);
}

static int shiftfs_iterate_shared(struct file *file, struct dir_context *ctx)
{
	const struct cred *oldcred;
	int err = -ENOTDIR;
	struct file *realfile = file-&gt;private_data;

	oldcred = shiftfs_override_creds(file-&gt;f_path.dentry-&gt;d_sb);
	err = iterate_dir(realfile, ctx);
	revert_creds(oldcred);

	return err;
}

const struct file_operations shiftfs_file_operations = {
	.open			= shiftfs_open,
	.release		= shiftfs_release,
	.llseek			= shiftfs_file_llseek,
	.read_iter		= shiftfs_read_iter,
	.write_iter		= shiftfs_write_iter,
	.fsync			= shiftfs_fsync,
	.mmap			= shiftfs_mmap,
	.fallocate		= shiftfs_fallocate,
	.fadvise		= shiftfs_fadvise,
	.unlocked_ioctl		= shiftfs_ioctl,
	.compat_ioctl		= shiftfs_compat_ioctl,
	.copy_file_range	= shiftfs_copy_file_range,
	.remap_file_range	= shiftfs_remap_file_range,
	.splice_read		= generic_file_splice_read,
	.splice_write		= iter_file_splice_write,
};

const struct file_operations shiftfs_dir_operations = {
	.open			= shiftfs_dir_open,
	.release		= shiftfs_dir_release,
	.compat_ioctl		= shiftfs_compat_ioctl,
	.fsync			= shiftfs_fsync,
	.iterate_shared		= shiftfs_iterate_shared,
	.llseek			= shiftfs_dir_llseek,
	.read			= generic_read_dir,
	.unlocked_ioctl		= shiftfs_ioctl,
};

static const struct address_space_operations shiftfs_aops = {
	/* For O_DIRECT dentry_open() checks f_mapping-&gt;a_ops-&gt;direct_IO */
	.direct_IO	= noop_direct_IO,
};

static void shiftfs_fill_inode(struct inode *inode, unsigned long ino,
			       umode_t mode, dev_t dev, struct dentry *dentry)
{
	struct inode *loweri;

	inode-&gt;i_ino = ino;
	inode-&gt;i_flags |= S_NOCMTIME;

	mode &amp;= S_IFMT;
	inode-&gt;i_mode = mode;
	switch (mode &amp; S_IFMT) {
	case S_IFDIR:
		inode-&gt;i_op = &amp;shiftfs_dir_inode_operations;
		inode-&gt;i_fop = &amp;shiftfs_dir_operations;
		break;
	case S_IFLNK:
		inode-&gt;i_op = &amp;shiftfs_symlink_inode_operations;
		break;
	case S_IFREG:
		inode-&gt;i_op = &amp;shiftfs_file_inode_operations;
		inode-&gt;i_fop = &amp;shiftfs_file_operations;
		inode-&gt;i_mapping-&gt;a_ops = &amp;shiftfs_aops;
		break;
	default:
		inode-&gt;i_op = &amp;shiftfs_special_inode_operations;
		init_special_inode(inode, mode, dev);
		break;
	}

	if (!dentry)
		return;

	loweri = dentry-&gt;d_inode;
	if (!loweri-&gt;i_op-&gt;get_link)
		inode-&gt;i_opflags |= IOP_NOFOLLOW;

	shiftfs_copyattr(loweri, inode);
	shiftfs_copyflags(loweri, inode);
	set_nlink(inode, loweri-&gt;i_nlink);
}

static int shiftfs_show_options(struct seq_file *m, struct dentry *dentry)
{
	struct super_block *sb = dentry-&gt;d_sb;
	struct shiftfs_super_info *sbinfo = sb-&gt;s_fs_info;

	if (sbinfo-&gt;mark)
		seq_show_option(m, "mark", NULL);

	if (sbinfo-&gt;passthrough)
		seq_printf(m, ",passthrough=%u", sbinfo-&gt;passthrough);

	return 0;
}

static int shiftfs_statfs(struct dentry *dentry, struct kstatfs *buf)
{
	struct super_block *sb = dentry-&gt;d_sb;
	struct shiftfs_super_info *sbinfo = sb-&gt;s_fs_info;
	struct dentry *root = sb-&gt;s_root;
	struct dentry *realroot = root-&gt;d_fsdata;
	struct path realpath = { .mnt = sbinfo-&gt;mnt, .dentry = realroot };
	int err;

	err = vfs_statfs(&amp;realpath, buf);
	if (err)
		return err;

	if (!shiftfs_passthrough_statfs(sbinfo))
		buf-&gt;f_type = sb-&gt;s_magic;

	return 0;
}

static void shiftfs_evict_inode(struct inode *inode)
{
	struct inode *loweri = inode-&gt;i_private;

	clear_inode(inode);

	if (loweri)
		iput(loweri);
}

static void shiftfs_put_super(struct super_block *sb)
{
	struct shiftfs_super_info *sbinfo = sb-&gt;s_fs_info;

	if (sbinfo) {
		mntput(sbinfo-&gt;mnt);
		put_cred(sbinfo-&gt;creator_cred);
		kfree(sbinfo);
	}
}

static const struct xattr_handler shiftfs_xattr_handler = {
	.prefix = "",
	.get    = shiftfs_xattr_get,
	.set    = shiftfs_xattr_set,
};

const struct xattr_handler *shiftfs_xattr_handlers[] = {
#ifdef CONFIG_SHIFT_FS_POSIX_ACL
	&amp;shiftfs_posix_acl_access_xattr_handler,
	&amp;shiftfs_posix_acl_default_xattr_handler,
#endif
	&amp;shiftfs_xattr_handler,
	NULL
};

static inline bool passthrough_is_subset(int old_flags, int new_flags)
{
	if ((new_flags &amp; old_flags) != new_flags)
		return false;

	return true;
}

static int shiftfs_super_check_flags(unsigned long old_flags,
				     unsigned long new_flags)
{
	if ((old_flags &amp; SB_RDONLY) &amp;&amp; !(new_flags &amp; SB_RDONLY))
		return -EPERM;

	if ((old_flags &amp; SB_NOSUID) &amp;&amp; !(new_flags &amp; SB_NOSUID))
		return -EPERM;

	if ((old_flags &amp; SB_NODEV) &amp;&amp; !(new_flags &amp; SB_NODEV))
		return -EPERM;

	if ((old_flags &amp; SB_NOEXEC) &amp;&amp; !(new_flags &amp; SB_NOEXEC))
		return -EPERM;

	if ((old_flags &amp; SB_NOATIME) &amp;&amp; !(new_flags &amp; SB_NOATIME))
		return -EPERM;

	if ((old_flags &amp; SB_NODIRATIME) &amp;&amp; !(new_flags &amp; SB_NODIRATIME))
		return -EPERM;

	if (!(old_flags &amp; SB_POSIXACL) &amp;&amp; (new_flags &amp; SB_POSIXACL))
		return -EPERM;

	return 0;
}

static int shiftfs_remount(struct super_block *sb, int *flags, char *data)
{
	int err;
	struct shiftfs_super_info new = {};
	struct shiftfs_super_info *info = sb-&gt;s_fs_info;

	err = shiftfs_parse_mount_options(&amp;new, data);
	if (err)
		return err;

	err = shiftfs_super_check_flags(sb-&gt;s_flags, *flags);
	if (err)
		return err;

	/* Mark mount option cannot be changed. */
	if (info-&gt;mark || (info-&gt;mark != new.mark))
		return -EPERM;

	if (info-&gt;passthrough != new.passthrough) {
		/* Don't allow exceeding passthrough options of mark mount. */
		if (!passthrough_is_subset(info-&gt;passthrough_mark,
					   info-&gt;passthrough))
			return -EPERM;

		info-&gt;passthrough = new.passthrough;
	}

	return 0;
}

static const struct super_operations shiftfs_super_ops = {
	.put_super	= shiftfs_put_super,
	.show_options	= shiftfs_show_options,
	.statfs		= shiftfs_statfs,
	.remount_fs	= shiftfs_remount,
	.evict_inode	= shiftfs_evict_inode,
};

struct shiftfs_data {
	void *data;
	const char *path;
};

static void shiftfs_super_force_flags(struct super_block *sb,
				      unsigned long lower_flags)
{
	sb-&gt;s_flags |= lower_flags &amp; (SB_RDONLY | SB_NOSUID | SB_NODEV |
				      SB_NOEXEC | SB_NOATIME | SB_NODIRATIME);

	if (!(lower_flags &amp; SB_POSIXACL))
		sb-&gt;s_flags &amp;= ~SB_POSIXACL;
}

static int shiftfs_fill_super(struct super_block *sb, void *raw_data,
			      int silent)
{
	int err;
	struct path path = {};
	struct shiftfs_super_info *sbinfo_mp;
	char *name = NULL;
	struct inode *inode = NULL;
	struct dentry *dentry = NULL;
	struct shiftfs_data *data = raw_data;
	struct shiftfs_super_info *sbinfo = NULL;

	if (!data-&gt;path)
		return -EINVAL;

	sb-&gt;s_fs_info = kzalloc(sizeof(*sbinfo), GFP_KERNEL);
	if (!sb-&gt;s_fs_info)
		return -ENOMEM;
	sbinfo = sb-&gt;s_fs_info;

	err = shiftfs_parse_mount_options(sbinfo, data-&gt;data);
	if (err)
		return err;

	/* to mount a mark, must be userns admin */
	if (!sbinfo-&gt;mark &amp;&amp; !ns_capable(current_user_ns(), CAP_SYS_ADMIN))
		return -EPERM;

	name = kstrdup(data-&gt;path, GFP_KERNEL);
	if (!name)
		return -ENOMEM;

	err = kern_path(name, LOOKUP_FOLLOW, &amp;path);
	if (err)
		goto out_free_name;

	if (!S_ISDIR(path.dentry-&gt;d_inode-&gt;i_mode)) {
		err = -ENOTDIR;
		goto out_put_path;
	}

	sb-&gt;s_flags |= SB_POSIXACL;

	if (sbinfo-&gt;mark) {
		struct cred *cred_tmp;
		struct super_block *lower_sb = path.mnt-&gt;mnt_sb;

		/* to mark a mount point, must root wrt lower s_user_ns */
		if (!ns_capable(lower_sb-&gt;s_user_ns, CAP_SYS_ADMIN)) {
			err = -EPERM;
			goto out_put_path;
		}

		/*
		 * this part is visible unshifted, so make sure no
		 * executables that could be used to give suid
		 * privileges
		 */
		sb-&gt;s_iflags = SB_I_NOEXEC;

		shiftfs_super_force_flags(sb, lower_sb-&gt;s_flags);

		/*
		 * Handle nesting of shiftfs mounts by referring this mark
		 * mount back to the original mark mount. This is more
		 * efficient and alleviates concerns about stack depth.
		 */
		if (lower_sb-&gt;s_magic == SHIFTFS_MAGIC) {
			sbinfo_mp = lower_sb-&gt;s_fs_info;

			/* Doesn't make sense to mark a mark mount */
			if (sbinfo_mp-&gt;mark) {
				err = -EINVAL;
				goto out_put_path;
			}

			if (!passthrough_is_subset(sbinfo_mp-&gt;passthrough,
						   sbinfo-&gt;passthrough)) {
				err = -EPERM;
				goto out_put_path;
			}

			sbinfo-&gt;mnt = mntget(sbinfo_mp-&gt;mnt);
			dentry = dget(path.dentry-&gt;d_fsdata);
			/*
			 * Copy up the passthrough mount options from the
			 * parent mark mountpoint.
			 */
			sbinfo-&gt;passthrough_mark = sbinfo_mp-&gt;passthrough_mark;
			sbinfo-&gt;creator_cred = get_cred(sbinfo_mp-&gt;creator_cred);
		} else {
			sbinfo-&gt;mnt = mntget(path.mnt);
			dentry = dget(path.dentry);
			/*
			 * For a new mark passthrough_mark and passthrough
			 * are identical.
			 */
			sbinfo-&gt;passthrough_mark = sbinfo-&gt;passthrough;

			cred_tmp = prepare_creds();
			if (!cred_tmp) {
				err = -ENOMEM;
				goto out_put_path;
			}
			/* Don't override disk quota limits or use reserved space. */
			cap_lower(cred_tmp-&gt;cap_effective, CAP_SYS_RESOURCE);
			sbinfo-&gt;creator_cred = cred_tmp;
		}
	} else {
		/*
		 * This leg executes if we're admin capable in the namespace,
		 * so be very careful.
		 */
		err = -EPERM;
		if (path.dentry-&gt;d_sb-&gt;s_magic != SHIFTFS_MAGIC)
			goto out_put_path;

		sbinfo_mp = path.dentry-&gt;d_sb-&gt;s_fs_info;
		if (!sbinfo_mp-&gt;mark)
			goto out_put_path;

		if (!passthrough_is_subset(sbinfo_mp-&gt;passthrough,
					   sbinfo-&gt;passthrough))
			goto out_put_path;

		sbinfo-&gt;mnt = mntget(sbinfo_mp-&gt;mnt);
		sbinfo-&gt;creator_cred = get_cred(sbinfo_mp-&gt;creator_cred);
		dentry = dget(path.dentry-&gt;d_fsdata);
		/*
		 * Copy up passthrough settings from mark mountpoint so we can
		 * verify when the overlay wants to remount with different
		 * passthrough settings.
		 */
		sbinfo-&gt;passthrough_mark = sbinfo_mp-&gt;passthrough;
		shiftfs_super_force_flags(sb, path.mnt-&gt;mnt_sb-&gt;s_flags);
	}

	sb-&gt;s_stack_depth = dentry-&gt;d_sb-&gt;s_stack_depth + 1;
	if (sb-&gt;s_stack_depth &gt; FILESYSTEM_MAX_STACK_DEPTH) {
		printk(KERN_ERR "shiftfs: maximum stacking depth exceeded\n");
		err = -EINVAL;
		goto out_put_path;
	}

	inode = new_inode(sb);
	if (!inode) {
		err = -ENOMEM;
		goto out_put_path;
	}
	shiftfs_fill_inode(inode, dentry-&gt;d_inode-&gt;i_ino, S_IFDIR, 0, dentry);

	ihold(dentry-&gt;d_inode);
	inode-&gt;i_private = dentry-&gt;d_inode;

	sb-&gt;s_magic = SHIFTFS_MAGIC;
	sb-&gt;s_maxbytes = MAX_LFS_FILESIZE;
	sb-&gt;s_op = &amp;shiftfs_super_ops;
	sb-&gt;s_xattr = shiftfs_xattr_handlers;
	sb-&gt;s_d_op = &amp;shiftfs_dentry_ops;
	sb-&gt;s_root = d_make_root(inode);
	if (!sb-&gt;s_root) {
		err = -ENOMEM;
		goto out_put_path;
	}

	sb-&gt;s_root-&gt;d_fsdata = dentry;
	sbinfo-&gt;userns = get_user_ns(dentry-&gt;d_sb-&gt;s_user_ns);
	shiftfs_copyattr(dentry-&gt;d_inode, sb-&gt;s_root-&gt;d_inode);

	dentry = NULL;
	err = 0;

out_put_path:
	path_put(&amp;path);

out_free_name:
	kfree(name);

	dput(dentry);

	return err;
}

static struct dentry *shiftfs_mount(struct file_system_type *fs_type,
				    int flags, const char *dev_name, void *data)
{
	struct shiftfs_data d = { data, dev_name };

	return mount_nodev(fs_type, flags, &amp;d, shiftfs_fill_super);
}

static struct file_system_type shiftfs_type = {
	.owner		= THIS_MODULE,
	.name		= "shiftfs",
	.mount		= shiftfs_mount,
	.kill_sb	= kill_anon_super,
	.fs_flags	= FS_USERNS_MOUNT,
};

static int __init shiftfs_init(void)
{
	return register_filesystem(&amp;shiftfs_type);
}

static void __exit shiftfs_exit(void)
{
	unregister_filesystem(&amp;shiftfs_type);
}

MODULE_ALIAS_FS("shiftfs");
MODULE_AUTHOR("James Bottomley");
MODULE_AUTHOR("Seth Forshee &lt;seth.forshee@canonical.com&gt;");
MODULE_AUTHOR("Christian Brauner &lt;christian.brauner@ubuntu.com&gt;");
MODULE_DESCRIPTION("id shifting filesystem");
MODULE_LICENSE("GPL v2");
module_init(shiftfs_init)
module_exit(shiftfs_exit)
</code></pre></td></tr></table>
</div> <!-- class=content -->
<div class='footer'>generated by <a href='https://git.zx2c4.com/cgit/about/'>cgit v1.1</a> at 2022-12-03 21:27:12 +0000</div>
</div> <!-- id=cgit -->
</body>
</html>

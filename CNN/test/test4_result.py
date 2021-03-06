import numpy as np

t4_should_be = np.array([[[[  30201.,   40150.,   50030.,   50915.,   51800.,   52685.,
                              41938.,   31290.],
                           [  41056.,   54480.,   67760.,   68840.,   69920.,   71000.,
                              56416.,   42016.],
                           [  51905.,   68750.,   85350.,   86575.,   87800.,   89025.,
                              70610.,   52490.],
                           [  58025.,   76750.,   95150.,   96375.,   97600.,   98825.,
                              78290.,   58130.],
                           [  64145.,   84750.,  104950.,  106175.,  107400.,  108625.,
                              85970.,   63770.],
                           [  70265.,   92750.,  114750.,  115975.,  117200.,  118425.,
                              93650.,   69410.],
                           [  53320.,   70240.,   86720.,   87600.,   88480.,   89360.,
                              70512.,   52144.],
                           [  37581.,   49390.,   60830.,   61415.,   62000.,   62585.,
                              49258.,   36330.]],
                          [[  67102.,   89951.,  113031.,  115416.,  117801.,  120186.,
                              96539.,   72691.],
                           [  95057.,  127281.,  159761.,  162841.,  165921.,  169001.,
                              135617.,  102017.],
                           [ 125406.,  167751.,  210351.,  214076.,  217801.,  221526.,
                             177611.,  133491.],
                           [ 143526.,  191751.,  240151.,  243876.,  247601.,  251326.,
                             201291.,  151131.],
                           [ 161646.,  215751.,  269951.,  273676.,  277401.,  281126.,
                             224971.,  168771.],
                           [ 179766.,  239751.,  299751.,  303476.,  307201.,  310926.,
                             248651.,  186411.],
                           [ 145721.,  194241.,  242721.,  245601.,  248481.,  251361.,
                             200913.,  150545.],
                           [ 110482.,  147191.,  183831.,  185916.,  188001.,  190086.,
                             151859.,  113731.]],
                          [[ 104003.,  139752.,  176032.,  179917.,  183802.,  187687.,
                             151140.,  114092.],
                           [ 149058.,  200082.,  251762.,  256842.,  261922.,  267002.,
                             214818.,  162018.],
                           [ 198907.,  266752.,  335352.,  341577.,  347802.,  354027.,
                             284612.,  214492.],
                           [ 229027.,  306752.,  385152.,  391377.,  397602.,  403827.,
                             324292.,  244132.],
                           [ 259147.,  346752.,  434952.,  441177.,  447402.,  453627.,
                             363972.,  273772.],
                           [ 289267.,  386752.,  484752.,  490977.,  497202.,  503427.,
                             403652.,  303412.],
                           [ 238122.,  318242.,  398722.,  403602.,  408482.,  413362.,
                             331314.,  248946.],
                           [ 183383.,  244992.,  306832.,  310417.,  314002.,  317587.,
                             254460.,  191132.]],
                          [[ 140904.,  189553.,  239033.,  244418.,  249803.,  255188.,
                             205741.,  155493.],
                           [ 203059.,  272883.,  343763.,  350843.,  357923.,  365003.,
                             294019.,  222019.],
                           [ 272408.,  365753.,  460353.,  469078.,  477803.,  486528.,
                             391613.,  295493.],
                           [ 314528.,  421753.,  530153.,  538878.,  547603.,  556328.,
                             447293.,  337133.],
                           [ 356648.,  477753.,  599953.,  608678.,  617403.,  626128.,
                             502973.,  378773.],
                           [ 398768.,  533753.,  669753.,  678478.,  687203.,  695928.,
                             558653.,  420413.],
                           [ 330523.,  442243.,  554723.,  561603.,  568483.,  575363.,
                             461715.,  347347.],
                           [ 256284.,  342793.,  429833.,  434918.,  440003.,  445088.,
                             357061.,  268533.]],
                          [[ 177805.,  239354.,  302034.,  308919.,  315804.,  322689.,
                             260342.,  196894.],
                           [ 257060.,  345684.,  435764.,  444844.,  453924.,  463004.,
                             373220.,  282020.],
                           [ 345909.,  464754.,  585354.,  596579.,  607804.,  619029.,
                             498614.,  376494.],
                           [ 400029.,  536754.,  675154.,  686379.,  697604.,  708829.,
                             570294.,  430134.],
                           [ 454149.,  608754.,  764954.,  776179.,  787404.,  798629.,
                             641974.,  483774.],
                           [ 508269.,  680754.,  854754.,  865979.,  877204.,  888429.,
                             713654.,  537414.],
                           [ 422924.,  566244.,  710724.,  719604.,  728484.,  737364.,
                             592116.,  445748.],
                           [ 329185.,  440594.,  552834.,  559419.,  566004.,  572589.,
                             459662.,  345934.]]],
                         [[[ 100473.,  132310.,  163310.,  164195.,  165080.,  165965.,
                             131026.,   96954.],
                           [ 127072.,  167120.,  206000.,  207080.,  208160.,  209240.,
                             164960.,  121888.],
                           [ 149825.,  196750.,  242150.,  243375.,  244600.,  245825.,
                             193490.,  142730.],
                           [ 155945.,  204750.,  251950.,  253175.,  254400.,  255625.,
                             201170.,  148370.],
                           [ 162065.,  212750.,  261750.,  262975.,  264200.,  265425.,
                             208850.,  154010.],
                           [ 168185.,  220750.,  271550.,  272775.,  274000.,  275225.,
                             216530.,  159650.],
                           [ 123976.,  162400.,  199360.,  200240.,  201120.,  202000.,
                             158576.,  116656.],
                           [  84813.,  110830.,  135710.,  136295.,  136880.,  137465.,
                              107626.,   78954.]],
                          [[ 252574.,  335711.,  418311.,  420696.,  423081.,  425466.,
                             339227.,  253555.],
                           [ 334673.,  444721.,  554001.,  557081.,  560161.,  563241.,
                             448961.,  335489.],
                           [ 415326.,  551751.,  687151.,  690876.,  694601.,  698326.,
                             556491.,  415731.],
                           [ 433446.,  575751.,  716951.,  720676.,  724401.,  728126.,
                             580171.,  433371.],
                           [ 451566.,  599751.,  746751.,  750476.,  754201.,  757926.,
                             603851.,  451011.],
                           [ 469686.,  623751.,  776551.,  780276.,  784001.,  787726.,
                             627531.,  468651.],
                           [ 369977.,  491201.,  611361.,  614241.,  617121.,  620001.,
                             493777.,  368657.],
                           [ 272914.,  362231.,  450711.,  452796.,  454881.,  456966.,
                             363827.,  271555.]],
                          [[ 404675.,  539112.,  673312.,  677197.,  681082.,  684967.,
                             547428.,  410156.],
                           [ 542274.,  722322.,  902002.,  907082.,  912162.,  917242.,
                             732962.,  549090.],
                           [ 680827.,  906752., 1132152., 1138377., 1144602., 1150827.,
                             919492.,  688732.],
                           [ 710947.,  946752., 1181952., 1188177., 1194402., 1200627.,
                             959172.,  718372.],
                           [ 741067.,  986752., 1231752., 1237977., 1244202., 1250427.,
                             998852.,  748012.],
                           [ 771187., 1026752., 1281552., 1287777., 1294002., 1300227.,
                             1038532.,  777652.],
                           [ 615978.,  820002., 1023362., 1028242., 1033122., 1038002.,
                             828978.,  620658.],
                           [ 461015.,  613632.,  765712.,  769297.,  772882.,  776467.,
                             620028.,  464156.]],
                          [[ 556776.,  742513.,  928313.,  933698.,  939083.,  944468.,
                             755629.,  566757.],
                           [ 749875.,  999923., 1250003., 1257083., 1264163., 1271243.,
                             1016963.,  762691.],
                           [ 946328., 1261753., 1577153., 1585878., 1594603., 1603328.,
                             1282493.,  961733.],
                           [ 988448., 1317753., 1646953., 1655678., 1664403., 1673128.,
                             1338173., 1003373.],
                           [1030568., 1373753., 1716753., 1725478., 1734203., 1742928.,
                            1393853., 1045013.],
                           [1072688., 1429753., 1786553., 1795278., 1804003., 1812728.,
                            1449533., 1086653.],
                           [ 861979., 1148803., 1435363., 1442243., 1449123., 1456003.,
                             1164179.,  872659.],
                           [ 649116.,  865033., 1080713., 1085798., 1090883., 1095968.,
                             876229.,  656757.]],
                          [[ 708877.,  945914., 1183314., 1190199., 1197084., 1203969.,
                             963830.,  723358.],
                           [ 957476., 1277524., 1598004., 1607084., 1616164., 1625244.,
                             1300964.,  976292.],
                           [1211829., 1616754., 2022154., 2033379., 2044604., 2055829.,
                            1645494., 1234734.],
                           [1265949., 1688754., 2111954., 2123179., 2134404., 2145629.,
                            1717174., 1288374.],
                           [1320069., 1760754., 2201754., 2212979., 2224204., 2235429.,
                            1788854., 1342014.],
                           [1374189., 1832754., 2291554., 2302779., 2314004., 2325229.,
                            1860534., 1395654.],
                           [1107980., 1477604., 1847364., 1856244., 1865124., 1874004.,
                            1499380., 1124660.],
                           [ 837217., 1116434., 1395714., 1402299., 1408884., 1415469.,
                             1132430.,  849358.]]]])

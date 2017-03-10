#include "Bigrams.h"
const std::map<char, const std::map<char, double>> Bigrams::PROB_2_GIVEN_1
{
	{' ', {
		{' ', 0.0},
		{'a', 0.05970135630966941},
		{'b', 0.057310016246508826},
		{'c', 0.09421149668680746},
		{'d', 0.06107957138423906},
		{'e', 0.04101787115970866},
		{'f', 0.04290721235464851},
		{'g', 0.032794216973038096},
		{'h', 0.035778828425914094},
		{'i', 0.03997736441466932},
		{'j', 0.009547105748343403},
		{'k', 0.008798671072087037},
		{'l', 0.030694948978660486},
		{'m', 0.05297457147551158},
		{'n', 0.02258082181778354},
		{'o', 0.027044048118873332},
		{'p', 0.07710702615870466},
		{'q', 0.005266424490242967},
		{'r', 0.062101823624979464},
		{'s', 0.11049451452145817},
		{'t', 0.050473704386557385},
		{'u', 0.030229459119037624},
		{'v', 0.016657235172778884},
		{'w', 0.024753107829356896},
		{'x', 0.0007210529198079626},
		{'y', 0.0033588287910041805},
		{'z', 0.0024187218196089887},
	}
	},
	{'a', {
		{' ', 0.02036860144968253},
		{'a', 0.0005337978310951284},
		{'b', 0.04998033376411755},
		{'c', 0.056877563634320394},
		{'d', 0.03983817497331011},
		{'e', 0.004747991234477721},
		{'f', 0.008639096476934316},
		{'g', 0.0321823902904984},
		{'h', 0.003947294487835028},
		{'i', 0.030974321514862055},
		{'j', 0.0009130752373995618},
		{'k', 0.011392369500477608},
		{'l', 0.1263274709220655},
		{'m', 0.03829297072540316},
		{'n', 0.12899646007754115},
		{'o', 0.0008849806147103444},
		{'p', 0.03729561161993594},
		{'q', 0.001095690284879474},
		{'r', 0.11048210372534698},
		{'s', 0.06406978704276002},
		{'t', 0.1638759341462044},
		{'u', 0.01830364668202506},
		{'v', 0.015704894083272462},
		{'w', 0.010296679215598134},
		{'x', 0.003961341799179637},
		{'y', 0.015058717761420464},
		{'z', 0.00495870090464685},
	}
	},
	{'b', {
		{' ', 0.009949704788978789},
		{'a', 0.12858080034987973},
		{'b', 0.0379400830964356},
		{'c', 0.0037721408265908593},
		{'d', 0.00448283402580363},
		{'e', 0.1363984255412202},
		{'f', 0.001585392521320796},
		{'g', 0.000656024491581019},
		{'h', 0.0016947299365842991},
		{'i', 0.12633938333697792},
		{'j', 0.003553465996063853},
		{'k', 0.0004373496610540127},
		{'l', 0.20079816313142357},
		{'m', 0.0037721408265908593},
		{'n', 0.002241417012901815},
		{'o', 0.1187951016837962},
		{'p', 0.0013667176907937897},
		{'q', 0.0},
		{'r', 0.08599387710474525},
		{'s', 0.0328558932866827},
		{'t', 0.007270938115022961},
		{'u', 0.07850426415919527},
		{'v', 0.0017493986442160508},
		{'w', 0.0014213863984255412},
		{'x', 5.466870763175159e-05},
		{'y', 0.009785698666083534},
		{'z', 0.0},
	}
	},
	{'c', {
		{' ', 0.04881594248863516},
		{'a', 0.14795432921027593},
		{'b', 7.92895654931811e-05},
		{'c', 0.017258695422349087},
		{'d', 0.0003171582619727244},
		{'e', 0.10196638122423089},
		{'f', 0.0},
		{'g', 2.64298551643937e-05},
		{'h', 0.11779786446770271},
		{'i', 0.07704302780420763},
		{'j', 0.0},
		{'k', 0.06707897240723121},
		{'l', 0.04022623956020721},
		{'m', 0.0001321492758219685},
		{'n', 0.0003964478274659055},
		{'o', 0.16954752087958558},
		{'p', 0.0001321492758219685},
		{'q', 0.0016915107305211967},
		{'r', 0.057881382810022204},
		{'s', 0.011391267575853684},
		{'t', 0.07397716460513797},
		{'u', 0.052278253515170736},
		{'v', 0.0},
		{'w', 5.28597103287874e-05},
		{'x', 0.0},
		{'y', 0.013267787292525637},
		{'z', 0.0006871762342742361},
	}
	},
	{'d', {
		{' ', 0.32624919829747534},
		{'a', 0.048685207859600024},
		{'b', 0.004576992595183954},
		{'c', 0.0026237537169844323},
		{'d', 0.019649000058305638},
		{'e', 0.2014751326453268},
		{'f', 0.002798670631450061},
		{'g', 0.012185878374438809},
		{'h', 0.003410879832079762},
		{'i', 0.15013701824966474},
		{'j', 0.0034400326511573667},
		{'k', 0.00026237537169844326},
		{'l', 0.029152819077604804},
		{'m', 0.006384467377995452},
		{'n', 0.0073756632266340156},
		{'o', 0.05110489184304122},
		{'p', 0.002419683983441199},
		{'q', 0.00026237537169844326},
		{'r', 0.03375896449186636},
		{'s', 0.043408547606553556},
		{'t', 0.001341029677569821},
		{'u', 0.03026062620255379},
		{'v', 0.003877324937321439},
		{'w', 0.005043437700425631},
		{'x', 2.9152819077604805e-05},
		{'y', 0.009941111305463239},
		{'z', 0.00014576409538802403},
	}
	},
	{'e', {
		{' ', 0.09915619588046723},
		{'a', 0.04225468882420133},
		{'b', 0.006973359372121302},
		{'c', 0.032987582445926526},
		{'d', 0.1093260621246177},
		{'e', 0.023591510372526624},
		{'f', 0.011726666421017724},
		{'g', 0.011229227311249493},
		{'h', 0.003583403957404473},
		{'i', 0.009331589225837355},
		{'j', 0.0011146320792954788},
		{'k', 0.001750248719554884},
		{'l', 0.04531301816573934},
		{'m', 0.026751169903091492},
		{'n', 0.09457791370352629},
		{'o', 0.007572128670916394},
		{'p', 0.01766830023213825},
		{'q', 0.0027451269390913447},
		{'r', 0.19354066104130588},
		{'s', 0.17468403404694352},
		{'t', 0.03875419138509156},
		{'u', 0.005241534323298574},
		{'v', 0.010888389402704595},
		{'w', 0.00775636537823796},
		{'x', 0.014305980323519658},
		{'y', 0.005886362798924058},
		{'z', 0.0012896569512509672},
	}
	},
	{'f', {
		{' ', 0.01961703790543181},
		{'a', 0.09175459163735834},
		{'b', 0.0016412661195779601},
		{'c', 0.0006252442360296991},
		{'d', 0.0009378663540445487},
		{'e', 0.12270418132082844},
		{'f', 0.09222352481438062},
		{'g', 0.0004689331770222743},
		{'h', 0.0015631105900742479},
		{'i', 0.18694802657288004},
		{'j', 0.00015631105900742478},
		{'k', 7.815552950371239e-05},
		{'l', 0.10957405236420477},
		{'m', 0.00039077764751856197},
		{'n', 0.0006252442360296991},
		{'o', 0.12270418132082844},
		{'p', 0.0007033997655334115},
		{'q', 0.0},
		{'r', 0.07377881985150449},
		{'s', 0.01570926143024619},
		{'t', 0.03540445486518171},
		{'u', 0.09863227823368503},
		{'v', 0.0},
		{'w', 0.0004689331770222743},
		{'x', 0.0},
		{'y', 0.023290347792106293},
		{'z', 0.0},
	}
	},
	{'g', {
		{' ', 0.3398945257372057},
		{'a', 0.07037807323776275},
		{'b', 0.0020797741959444403},
		{'c', 0.00022283294956547574},
		{'d', 0.0008170541484067444},
		{'e', 0.13013444254623785},
		{'f', 0.0013741365223204338},
		{'g', 0.03141944588873208},
		{'h', 0.03925573794845131},
		{'i', 0.08036841714328159},
		{'j', 0.00014855529971031717},
		{'k', 0.00018569412463789647},
		{'l', 0.054891183242962195},
		{'m', 0.0066107108371091135},
		{'n', 0.027037064547277723},
		{'o', 0.03988709797222016},
		{'p', 0.0006684988486964273},
		{'q', 0.0},
		{'r', 0.07795439352298893},
		{'s', 0.040109930921785636},
		{'t', 0.002265468320582337},
		{'u', 0.037435935526999926},
		{'v', 0.0},
		{'w', 0.0020797741959444403},
		{'x', 0.0},
		{'y', 0.01463269702146624},
		{'z', 0.00014855529971031717},
	}
	},
	{'h', {
		{' ', 0.06234341877047601},
		{'a', 0.156484871844286},
		{'b', 0.004432453266525342},
		{'c', 0.001011755636924263},
		{'d', 0.0016380805550202352},
		{'e', 0.2438812873386009},
		{'f', 0.003227982270186934},
		{'g', 0.00028907303912121797},
		{'h', 0.0016380805550202352},
		{'i', 0.15725573328194256},
		{'j', 0.0003372518789747543},
		{'k', 0.0005299672383888996},
		{'l', 0.01349007515899017},
		{'m', 0.012044709963384082},
		{'n', 0.00852765465407593},
		{'o', 0.15513586432838697},
		{'p', 0.0017344382347273077},
		{'q', 9.635767970707265e-05},
		{'r', 0.032038928502601656},
		{'s', 0.02033147041819233},
		{'t', 0.03704952784736944},
		{'u', 0.038880323761803816},
		{'v', 4.8178839853536324e-05},
		{'w', 0.005299672383888996},
		{'x', 0.0},
		{'y', 0.04225284255155136},
		{'z', 0.0},
	}
	},
	{'i', {
		{' ', 0.004661492653878069},
		{'a', 0.04052569922389808},
		{'b', 0.01508273539317616},
		{'c', 0.0841021135354127},
		{'d', 0.030787816664226093},
		{'e', 0.07778103187387124},
		{'f', 0.019915068091960756},
		{'g', 0.026443598379460146},
		{'h', 0.0005857372968223752},
		{'i', 0.0005125201347195783},
		{'j', 0.0002806657880607214},
		{'k', 0.003673060965490311},
		{'l', 0.05472982867184068},
		{'m', 0.030568165177917703},
		{'n', 0.25030507150876163},
		{'o', 0.07181383316249329},
		{'p', 0.019024259286376726},
		{'q', 0.0019524576560745839},
		{'r', 0.026297164055254552},
		{'s', 0.09939229755454679},
		{'t', 0.07444965099819398},
		{'u', 0.00408795821740616},
		{'v', 0.029506516327427148},
		{'w', 0.00031727436911211987},
		{'x', 0.002867672182359545},
		{'y', 0.00010982574315419534},
		{'z', 0.030226485088104653},
	}
	},
	{'j', {
		{' ', 0.002844141069397042},
		{'a', 0.2150170648464164},
		{'b', 0.0},
		{'c', 0.0005688282138794084},
		{'d', 0.0},
		{'e', 0.1825938566552901},
		{'f', 0.0},
		{'g', 0.0},
		{'h', 0.0},
		{'i', 0.07963594994311718},
		{'j', 0.0022753128555176336},
		{'k', 0.0005688282138794084},
		{'l', 0.0},
		{'m', 0.0},
		{'n', 0.0017064846416382253},
		{'o', 0.22184300341296928},
		{'p', 0.0},
		{'q', 0.0},
		{'r', 0.0},
		{'s', 0.0},
		{'t', 0.0},
		{'u', 0.29294653014789535},
		{'v', 0.0},
		{'w', 0.0},
		{'x', 0.0},
		{'y', 0.0},
		{'z', 0.0},
	}
	},
	{'k', {
		{' ', 0.11464342702835399},
		{'a', 0.055480544985884374},
		{'b', 0.011047011169755738},
		{'c', 0.0014729348226340984},
		{'d', 0.003436847919479563},
		{'e', 0.29127286117589296},
		{'f', 0.005768994721983552},
		{'g', 0.0009819565484227323},
		{'h', 0.00969682091567448},
		{'i', 0.19344544003927827},
		{'j', 0.0011047011169755738},
		{'k', 0.0033141033509267214},
		{'l', 0.049711550263900825},
		{'m', 0.008469375230146067},
		{'n', 0.03535043574321836},
		{'o', 0.021234810359641587},
		{'p', 0.005155271879219344},
		{'q', 0.0},
		{'r', 0.012151712286731313},
		{'s', 0.1182030195163864},
		{'t', 0.006628206701853443},
		{'u', 0.011537989443967105},
		{'v', 0.0009819565484227323},
		{'w', 0.010310543758438689},
		{'x', 0.0},
		{'y', 0.02859948447281208},
		{'z', 0.0},
	}
	},
	{'l', {
		{' ', 0.06663352555179956},
		{'a', 0.11815470272419965},
		{'b', 0.0030622390137204215},
		{'c', 0.005766553986876119},
		{'d', 0.014833963014515809},
		{'e', 0.19685822231059852},
		{'f', 0.005170013919268244},
		{'g', 0.003499701729966196},
		{'h', 0.0012527341419765361},
		{'i', 0.16786637502485582},
		{'j', 3.9769337840524956e-05},
		{'k', 0.006502286736925831},
		{'l', 0.10087492543249155},
		{'m', 0.006005170013919268},
		{'n', 0.004474050507059057},
		{'o', 0.08647842513422152},
		{'p', 0.0050507059057466695},
		{'q', 0.00011930801352157487},
		{'r', 0.0011135414595346987},
		{'s', 0.031676277589978125},
		{'t', 0.020003976933784053},
		{'u', 0.03559355736726984},
		{'v', 0.005786438655796381},
		{'w', 0.0013521574865778484},
		{'x', 3.9769337840524956e-05},
		{'y', 0.11165241598727381},
		{'z', 0.00013919268244183734},
	}
	},
	{'m', {
		{' ', 0.06372950021424954},
		{'a', 0.1708542713567839},
		{'b', 0.050329165205874334},
		{'c', 0.0009738615558412216},
		{'d', 0.0005064080090374353},
		{'e', 0.19134431849168324},
		{'f', 0.002882630205290016},
		{'g', 0.0001168633867009466},
		{'h', 0.0006232713957383818},
		{'i', 0.17069845350784932},
		{'j', 0.0001168633867009466},
		{'k', 0.0003505901601028398},
		{'l', 0.004168127459000429},
		{'m', 0.04210977367457442},
		{'n', 0.008686845078103697},
		{'o', 0.10591718281329127},
		{'p', 0.08912780959058861},
		{'q', 0.00015581784893459546},
		{'r', 0.0012854972537104125},
		{'s', 0.041720229052237934},
		{'t', 0.0007790892446729773},
		{'u', 0.0412917299676678},
		{'v', 0.0006232713957383818},
		{'w', 0.000856998169140275},
		{'x', 0.0},
		{'y', 0.010751431576487086},
		{'z', 0.0},
	}
	},
	{'n', {
		{' ', 0.08171158261298325},
		{'a', 0.06334458158060988},
		{'b', 0.003436108414613476},
		{'c', 0.05613337647729549},
		{'d', 0.06434613784495909},
		{'e', 0.11764433966625064},
		{'f', 0.013436262500192607},
		{'g', 0.18513382332547496},
		{'h', 0.004684201605571735},
		{'i', 0.07331391855036287},
		{'j', 0.0021726066657421533},
		{'k', 0.012943188646974529},
		{'l', 0.006148014607312902},
		{'m', 0.003975407941570749},
		{'n', 0.016856962356893018},
		{'o', 0.045085440453627945},
		{'p', 0.004776652953050124},
		{'q', 0.0020801553182637636},
		{'r', 0.004730427279310929},
		{'s', 0.09012465523351669},
		{'t', 0.11635002080155318},
		{'u', 0.013235951247322762},
		{'v', 0.008397664062620378},
		{'w', 0.0029122174455692693},
		{'x', 0.0004622567373919475},
		{'y', 0.005223501132529006},
		{'z', 0.0013405445384366476},
	}
	},
	{'o', {
		{' ', 0.012040634964888742},
		{'a', 0.018818937427033056},
		{'b', 0.01916743626827441},
		{'c', 0.033804387600411226},
		{'d', 0.026799560891460034},
		{'e', 0.010489815121364722},
		{'f', 0.010367840526930247},
		{'g', 0.03892732056665912},
		{'h', 0.00243949188868947},
		{'i', 0.021467528620467337},
		{'j', 0.0006447228562965028},
		{'k', 0.009967066859502691},
		{'l', 0.06980431790064298},
		{'m', 0.05894857899597484},
		{'n', 0.19648364669187474},
		{'o', 0.042778232762376064},
		{'p', 0.04094861384585896},
		{'q', 0.0011674711181585322},
		{'r', 0.13293488299151404},
		{'s', 0.0529369739845615},
		{'t', 0.04851103870079632},
		{'u', 0.07837738939518026},
		{'v', 0.02646848699228075},
		{'w', 0.02988377563644601},
		{'x', 0.0069699768248270575},
		{'y', 0.00613357960584781},
		{'z', 0.0027182909616825525},
	}
	},
	{'p', {
		{' ', 0.02760004543217355},
		{'a', 0.10858289478665809},
		{'b', 0.001855147086661871},
		{'c', 0.0016658463635331087},
		{'d', 0.0009465036156438118},
		{'e', 0.16874266459697876},
		{'f', 0.0015144057850300988},
		{'g', 0.0004921818801347821},
		{'h', 0.07363798129708855},
		{'i', 0.10169234846477114},
		{'j', 0.0003786014462575247},
		{'k', 0.0010222239048953167},
		{'l', 0.07462234505735812},
		{'m', 0.002423049256048158},
		{'n', 0.002423049256048158},
		{'o', 0.1080907129065233},
		{'p', 0.052928482186801955},
		{'q', 0.0},
		{'r', 0.13606935978495438},
		{'s', 0.042668382993223036},
		{'t', 0.038352326505887255},
		{'u', 0.04217620111308825},
		{'v', 0.0},
		{'w', 0.0017415666527846136},
		{'x', 0.0},
		{'y', 0.010335819482830425},
		{'z', 3.786014462575247e-05},
	}
	},
	{'q', {
		{' ', 0.0029205607476635513},
		{'a', 0.0017523364485981308},
		{'b', 0.0},
		{'c', 0.0},
		{'d', 0.0},
		{'e', 0.0005841121495327102},
		{'f', 0.0},
		{'g', 0.0},
		{'h', 0.0},
		{'i', 0.0040887850467289715},
		{'j', 0.0},
		{'k', 0.0},
		{'l', 0.0},
		{'m', 0.0},
		{'n', 0.0},
		{'o', 0.0011682242990654205},
		{'p', 0.0},
		{'q', 0.0},
		{'r', 0.0005841121495327102},
		{'s', 0.0005841121495327102},
		{'t', 0.0011682242990654205},
		{'u', 0.9871495327102804},
		{'v', 0.0},
		{'w', 0.0},
		{'x', 0.0},
		{'y', 0.0},
		{'z', 0.0},
	}
	},
	{'r', {
		{' ', 0.11119160774313203},
		{'a', 0.12653587573895908},
		{'b', 0.01144662107337429},
		{'c', 0.01770603917932074},
		{'d', 0.023791584560102004},
		{'e', 0.18392836443723196},
		{'f', 0.005781268111742205},
		{'g', 0.012402921061782776},
		{'h', 0.0036803060159962906},
		{'i', 0.12617364089486496},
		{'j', 0.0006375333256056566},
		{'k', 0.010359916541091922},
		{'l', 0.01059174684131216},
		{'m', 0.021821027008229976},
		{'n', 0.017169931610061435},
		{'o', 0.08945751709748465},
		{'p', 0.009896255940651444},
		{'q', 0.0005505969630230671},
		{'r', 0.022154283064796568},
		{'s', 0.09991885939492291},
		{'t', 0.03531065260229512},
		{'u', 0.026790889069201344},
		{'v', 0.006882462037788339},
		{'w', 0.0029268575402805145},
		{'x', 7.244696881882462e-05},
		{'y', 0.022487539121363163},
		{'z', 0.00033325605656659324},
	}
	},
	{'s', {
		{' ', 0.4298450868161801},
		{'a', 0.026458835811224306},
		{'b', 0.0017519229153917229},
		{'c', 0.02996268164200775},
		{'d', 0.0009839567059049402},
		{'e', 0.06968093403890228},
		{'f', 0.0019919123558563424},
		{'g', 0.0008399630416261684},
		{'h', 0.04439804648595462},
		{'i', 0.053349652615284925},
		{'j', 0.00022798996844138858},
		{'k', 0.007307678462147665},
		{'l', 0.015911299902804276},
		{'m', 0.018083204339009083},
		{'n', 0.00969557339477063},
		{'o', 0.024850906560111356},
		{'p', 0.025834863266016295},
		{'q', 0.003155861142109747},
		{'r', 0.0008999604017423233},
		{'s', 0.06866097891692766},
		{'t', 0.12388254916783661},
		{'u', 0.02857074288731296},
		{'v', 0.00017999208034846466},
		{'w', 0.006191727563987184},
		{'x', 0.0},
		{'y', 0.007259680574054741},
		{'z', 2.3998944046461955e-05},
	}
	},
	{'t', {
		{' ', 0.09714065039342205},
		{'a', 0.08331858335881057},
		{'b', 0.002864176870967223},
		{'c', 0.009718892303731476},
		{'d', 0.000820634946176002},
		{'e', 0.1935089384845608},
		{'f', 0.0034595394789772634},
		{'g', 0.0013838157915909055},
		{'h', 0.051877001303361384},
		{'i', 0.21716253399198673},
		{'j', 0.00012872705038054934},
		{'k', 8.045440648784334e-05},
		{'l', 0.018794149355560202},
		{'m', 0.0038618115114164805},
		{'n', 0.0030733583278356154},
		{'o', 0.07443641688255266},
		{'p', 0.0014320884354836114},
		{'q', 0.0},
		{'r', 0.07731668463481745},
		{'s', 0.061048803642975526},
		{'t', 0.03161858174972243},
		{'u', 0.03223003523903004},
		{'v', 0.000144817931678118},
		{'w', 0.005647899335446602},
		{'x', 1.6090881297568668e-05},
		{'y', 0.02683959000434454},
		{'z', 0.002075723687386358},
	}
	},
	{'u', {
		{' ', 0.0031376064545047063},
		{'a', 0.03941217903566626},
		{'b', 0.03816353973234296},
		{'c', 0.04171735928795543},
		{'d', 0.030383556380867004},
		{'e', 0.03691490042901966},
		{'f', 0.012326311071268489},
		{'g', 0.02490875328168022},
		{'h', 0.00025613113914324135},
		{'i', 0.03710699878337709},
		{'j', 0.0006723442402510085},
		{'k', 0.003233655631683422},
		{'l', 0.10331689825190497},
		{'m', 0.06832298136645963},
		{'n', 0.16504450278542615},
		{'o', 0.008356278414548248},
		{'p', 0.03784337580841391},
		{'q', 0.00016008196196452585},
		{'r', 0.12313504514311327},
		{'s', 0.1294422744445156},
		{'t', 0.08529166933469937},
		{'u', 0.0005442786706793878},
		{'v', 0.002881475315361465},
		{'w', 0.00019209835435743102},
		{'x', 0.0029455081001472753},
		{'y', 0.0007043606326439137},
		{'z', 0.003585835948005379},
	}
	},
	{'v', {
		{' ', 0.002468373958654736},
		{'a', 0.14625115705029312},
		{'b', 0.0},
		{'c', 0.00010284891494394734},
		{'d', 0.00020569782988789467},
		{'e', 0.5362542425177415},
		{'f', 0.0},
		{'g', 0.00010284891494394734},
		{'h', 0.0},
		{'i', 0.20970893757070863},
		{'j', 0.0},
		{'k', 0.0},
		{'l', 0.000308546744831842},
		{'m', 0.0},
		{'n', 0.000617093489663684},
		{'o', 0.08073639823099867},
		{'p', 0.0},
		{'q', 0.0},
		{'r', 0.002468373958654736},
		{'s', 0.0009256402344955261},
		{'t', 0.000308546744831842},
		{'u', 0.012958963282937365},
		{'v', 0.0022626761287668413},
		{'w', 0.0},
		{'x', 0.0},
		{'y', 0.004113956597757894},
		{'z', 0.00020569782988789467},
	}
	},
	{'w', {
		{' ', 0.039785482664005986},
		{'a', 0.20541282115240708},
		{'b', 0.011224744325268148},
		{'c', 0.003117984534796707},
		{'d', 0.013719131953105512},
		{'e', 0.16537789972561737},
		{'f', 0.006111249688201546},
		{'g', 0.0014966325767024195},
		{'h', 0.06872037914691943},
		{'i', 0.15876777251184834},
		{'j', 0.0001247193813918683},
		{'k', 0.007857321027687703},
		{'l', 0.031055125966575205},
		{'m', 0.004365178348715391},
		{'n', 0.05125966575205787},
		{'o', 0.12696433025692191},
		{'p', 0.0051134946370666005},
		{'q', 0.0},
		{'r', 0.036418059366425545},
		{'s', 0.048016961835869294},
		{'t', 0.004739336492890996},
		{'u', 0.002494387627837366},
		{'v', 0.0},
		{'w', 0.0016213519580942878},
		{'x', 0.0},
		{'y', 0.005238214018458469},
		{'z', 0.0009977550511349464},
	}
	},
	{'x', {
		{' ', 0.0974981604120677},
		{'a', 0.06622516556291391},
		{'b', 0.001839587932303164},
		{'c', 0.07358351729212656},
		{'d', 0.0},
		{'e', 0.15783664459161148},
		{'f', 0.003679175864606328},
		{'g', 0.0011037527593818985},
		{'h', 0.025386313465783666},
		{'i', 0.17292126563649743},
		{'j', 0.0},
		{'k', 0.0},
		{'l', 0.006254598969830758},
		{'m', 0.002207505518763797},
		{'n', 0.0011037527593818985},
		{'o', 0.04525386313465784},
		{'p', 0.14091243561442238},
		{'q', 0.0011037527593818985},
		{'r', 0.0},
		{'s', 0.0051508462104488595},
		{'t', 0.12178072111846946},
		{'u', 0.03899926416482708},
		{'v', 0.001839587932303164},
		{'w', 0.004047093451066961},
		{'x', 0.0033112582781456954},
		{'y', 0.027961736571008096},
		{'z', 0.0},
	}
	},
	{'y', {
		{' ', 0.6374881666140738},
		{'a', 0.024865888292836858},
		{'b', 0.008078258125591669},
		{'c', 0.02120542757967813},
		{'d', 0.011612496055538024},
		{'e', 0.0364152729567687},
		{'f', 0.0033449037551278008},
		{'g', 0.006942253076680341},
		{'h', 0.0027769012306721364},
		{'i', 0.03401704007573367},
		{'j', 0.0004417797412432944},
		{'k', 0.0005680025244556643},
		{'l', 0.023224992111076048},
		{'m', 0.02606500473335437},
		{'n', 0.019438308614704955},
		{'o', 0.018049857999368885},
		{'p', 0.02991479962133165},
		{'q', 0.0},
		{'r', 0.016598295992426633},
		{'s', 0.05250867781634585},
		{'t', 0.011738718838750394},
		{'u', 0.002019564531397917},
		{'v', 0.0008204480908804039},
		{'w', 0.006626696118649416},
		{'x', 0.0017671189649731776},
		{'y', 0.0},
		{'z', 0.0034711265383401703},
	}
	},
	{'z', {
		{' ', 0.01341136308217508},
		{'a', 0.1350890026822726},
		{'b', 0.000487685930260912},
		{'c', 0.000487685930260912},
		{'d', 0.000243842965130456},
		{'e', 0.47841989758595466},
		{'f', 0.0},
		{'g', 0.000487685930260912},
		{'h', 0.00121921482565228},
		{'i', 0.1850768105340161},
		{'j', 0.000243842965130456},
		{'k', 0.000975371860521824},
		{'l', 0.030480370641306997},
		{'m', 0.001950743721043648},
		{'n', 0.000243842965130456},
		{'o', 0.058034625701048524},
		{'p', 0.00243842965130456},
		{'q', 0.000731528895391368},
		{'r', 0.0},
		{'s', 0.000243842965130456},
		{'t', 0.000975371860521824},
		{'u', 0.007802974884174592},
		{'v', 0.001463057790782736},
		{'w', 0.000975371860521824},
		{'x', 0.0},
		{'y', 0.017800536454523286},
		{'z', 0.06071689831748354},
	}
	},
};

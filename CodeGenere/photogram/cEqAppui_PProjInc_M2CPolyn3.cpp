// File Automatically generated by eLiSe
#include "general/all.h"
#include "private/all.h"
#include "cEqAppui_PProjInc_M2CPolyn3.h"


cEqAppui_PProjInc_M2CPolyn3::cEqAppui_PProjInc_M2CPolyn3():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("Intr",0,17));
   AddIntRef (cIncIntervale("Orient",17,23));
   AddIntRef (cIncIntervale("Tmp_PTer",23,26));
   Close(false);
}



void cEqAppui_PProjInc_M2CPolyn3::ComputeVal()
{
   double tmp0_ = mCompCoord[17];
   double tmp1_ = mCompCoord[18];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = mCompCoord[23];
   double tmp4_ = mCompCoord[24];
   double tmp5_ = mCompCoord[25];
   double tmp6_ = sin(tmp0_);
   double tmp7_ = cos(tmp0_);
   double tmp8_ = sin(tmp1_);
   double tmp9_ = mCompCoord[19];
   double tmp10_ = mLocProjI_x*tmp3_;
   double tmp11_ = mLocProjP0_x+tmp10_;
   double tmp12_ = mLocProjJ_x*tmp4_;
   double tmp13_ = tmp11_+tmp12_;
   double tmp14_ = mLocProjK_x*tmp5_;
   double tmp15_ = tmp13_+tmp14_;
   double tmp16_ = mCompCoord[20];
   double tmp17_ = (tmp15_)-tmp16_;
   double tmp18_ = sin(tmp9_);
   double tmp19_ = -(tmp18_);
   double tmp20_ = -(tmp8_);
   double tmp21_ = cos(tmp9_);
   double tmp22_ = mLocProjI_y*tmp3_;
   double tmp23_ = mLocProjP0_y+tmp22_;
   double tmp24_ = mLocProjJ_y*tmp4_;
   double tmp25_ = tmp23_+tmp24_;
   double tmp26_ = mLocProjK_y*tmp5_;
   double tmp27_ = tmp25_+tmp26_;
   double tmp28_ = mCompCoord[21];
   double tmp29_ = (tmp27_)-tmp28_;
   double tmp30_ = mLocProjI_z*tmp3_;
   double tmp31_ = mLocProjP0_z+tmp30_;
   double tmp32_ = mLocProjJ_z*tmp4_;
   double tmp33_ = tmp31_+tmp32_;
   double tmp34_ = mLocProjK_z*tmp5_;
   double tmp35_ = tmp33_+tmp34_;
   double tmp36_ = mCompCoord[22];
   double tmp37_ = (tmp35_)-tmp36_;
   double tmp38_ = -(tmp6_);
   double tmp39_ = tmp7_*tmp20_;
   double tmp40_ = tmp6_*tmp20_;
   double tmp41_ = mCompCoord[0];
   double tmp42_ = tmp38_*tmp19_;
   double tmp43_ = tmp39_*tmp21_;
   double tmp44_ = tmp42_+tmp43_;
   double tmp45_ = (tmp44_)*(tmp17_);
   double tmp46_ = tmp7_*tmp19_;
   double tmp47_ = tmp40_*tmp21_;
   double tmp48_ = tmp46_+tmp47_;
   double tmp49_ = (tmp48_)*(tmp29_);
   double tmp50_ = tmp45_+tmp49_;
   double tmp51_ = tmp2_*tmp21_;
   double tmp52_ = tmp51_*(tmp37_);
   double tmp53_ = tmp50_+tmp52_;
   double tmp54_ = tmp41_/(tmp53_);
   double tmp55_ = tmp7_*tmp2_;
   double tmp56_ = tmp55_*(tmp17_);
   double tmp57_ = tmp6_*tmp2_;
   double tmp58_ = tmp57_*(tmp29_);
   double tmp59_ = tmp56_+tmp58_;
   double tmp60_ = tmp8_*(tmp37_);
   double tmp61_ = tmp59_+tmp60_;
   double tmp62_ = (tmp61_)*(tmp54_);
   double tmp63_ = mCompCoord[1];
   double tmp64_ = tmp62_+tmp63_;
   double tmp65_ = (tmp64_)-mLocPolyn3_State_1_0;
   double tmp66_ = (tmp65_)/mLocPolyn3_State_0_0;
   double tmp67_ = tmp38_*tmp21_;
   double tmp68_ = tmp39_*tmp18_;
   double tmp69_ = tmp67_+tmp68_;
   double tmp70_ = (tmp69_)*(tmp17_);
   double tmp71_ = tmp7_*tmp21_;
   double tmp72_ = tmp40_*tmp18_;
   double tmp73_ = tmp71_+tmp72_;
   double tmp74_ = (tmp73_)*(tmp29_);
   double tmp75_ = tmp70_+tmp74_;
   double tmp76_ = tmp2_*tmp18_;
   double tmp77_ = tmp76_*(tmp37_);
   double tmp78_ = tmp75_+tmp77_;
   double tmp79_ = (tmp78_)*(tmp54_);
   double tmp80_ = mCompCoord[2];
   double tmp81_ = tmp79_+tmp80_;
   double tmp82_ = (tmp81_)-mLocPolyn3_State_2_0;
   double tmp83_ = (tmp82_)/mLocPolyn3_State_0_0;
   double tmp84_ = (tmp66_)*(tmp66_);
   double tmp85_ = (tmp83_)*(tmp83_);
   double tmp86_ = mCompCoord[3];
   double tmp87_ = mCompCoord[4];
   double tmp88_ = mCompCoord[5];
   double tmp89_ = (tmp66_)*(tmp83_);
   double tmp90_ = mCompCoord[6];
   double tmp91_ = tmp84_*(tmp66_);
   double tmp92_ = (tmp83_)*(tmp66_);
   double tmp93_ = tmp92_*(tmp66_);
   double tmp94_ = tmp85_*(tmp66_);
   double tmp95_ = (tmp83_)*tmp85_;

  mVal[0] = ((mLocPolyn3_State_1_0+(((1+tmp86_)*(tmp66_)+tmp87_*(tmp83_))-tmp88_*2*tmp84_+tmp90_*tmp89_+mCompCoord[7]*tmp85_)*mLocPolyn3_State_0_0+(mCompCoord[9]*tmp91_+mCompCoord[10]*tmp93_+mCompCoord[11]*tmp94_+mCompCoord[12]*tmp95_)*mLocPolyn3_State_0_0)-mLocXIm)*mLocScNorm;

  mVal[1] = ((mLocPolyn3_State_2_0+(((1-tmp86_)*(tmp83_)+tmp87_*(tmp66_)+tmp88_*tmp89_)-tmp90_*2*tmp85_+mCompCoord[8]*tmp84_)*mLocPolyn3_State_0_0+(mCompCoord[13]*tmp91_+mCompCoord[14]*tmp93_+mCompCoord[15]*tmp94_+mCompCoord[16]*tmp95_)*mLocPolyn3_State_0_0)-mLocYIm)*mLocScNorm;

}


void cEqAppui_PProjInc_M2CPolyn3::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[17];
   double tmp1_ = mCompCoord[18];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = mCompCoord[23];
   double tmp4_ = mCompCoord[24];
   double tmp5_ = mCompCoord[25];
   double tmp6_ = sin(tmp0_);
   double tmp7_ = cos(tmp0_);
   double tmp8_ = sin(tmp1_);
   double tmp9_ = mCompCoord[19];
   double tmp10_ = mLocProjI_x*tmp3_;
   double tmp11_ = mLocProjP0_x+tmp10_;
   double tmp12_ = mLocProjJ_x*tmp4_;
   double tmp13_ = tmp11_+tmp12_;
   double tmp14_ = mLocProjK_x*tmp5_;
   double tmp15_ = tmp13_+tmp14_;
   double tmp16_ = mCompCoord[20];
   double tmp17_ = (tmp15_)-tmp16_;
   double tmp18_ = sin(tmp9_);
   double tmp19_ = -(tmp18_);
   double tmp20_ = -(tmp8_);
   double tmp21_ = cos(tmp9_);
   double tmp22_ = mLocProjI_y*tmp3_;
   double tmp23_ = mLocProjP0_y+tmp22_;
   double tmp24_ = mLocProjJ_y*tmp4_;
   double tmp25_ = tmp23_+tmp24_;
   double tmp26_ = mLocProjK_y*tmp5_;
   double tmp27_ = tmp25_+tmp26_;
   double tmp28_ = mCompCoord[21];
   double tmp29_ = (tmp27_)-tmp28_;
   double tmp30_ = mLocProjI_z*tmp3_;
   double tmp31_ = mLocProjP0_z+tmp30_;
   double tmp32_ = mLocProjJ_z*tmp4_;
   double tmp33_ = tmp31_+tmp32_;
   double tmp34_ = mLocProjK_z*tmp5_;
   double tmp35_ = tmp33_+tmp34_;
   double tmp36_ = mCompCoord[22];
   double tmp37_ = (tmp35_)-tmp36_;
   double tmp38_ = -(tmp6_);
   double tmp39_ = tmp7_*tmp20_;
   double tmp40_ = tmp6_*tmp20_;
   double tmp41_ = mCompCoord[0];
   double tmp42_ = tmp38_*tmp19_;
   double tmp43_ = tmp39_*tmp21_;
   double tmp44_ = tmp42_+tmp43_;
   double tmp45_ = (tmp44_)*(tmp17_);
   double tmp46_ = tmp7_*tmp19_;
   double tmp47_ = tmp40_*tmp21_;
   double tmp48_ = tmp46_+tmp47_;
   double tmp49_ = (tmp48_)*(tmp29_);
   double tmp50_ = tmp45_+tmp49_;
   double tmp51_ = tmp2_*tmp21_;
   double tmp52_ = tmp51_*(tmp37_);
   double tmp53_ = tmp50_+tmp52_;
   double tmp54_ = tmp41_/(tmp53_);
   double tmp55_ = tmp7_*tmp2_;
   double tmp56_ = tmp55_*(tmp17_);
   double tmp57_ = tmp6_*tmp2_;
   double tmp58_ = tmp57_*(tmp29_);
   double tmp59_ = tmp56_+tmp58_;
   double tmp60_ = tmp8_*(tmp37_);
   double tmp61_ = tmp59_+tmp60_;
   double tmp62_ = (tmp61_)*(tmp54_);
   double tmp63_ = mCompCoord[1];
   double tmp64_ = tmp62_+tmp63_;
   double tmp65_ = (tmp64_)-mLocPolyn3_State_1_0;
   double tmp66_ = (tmp65_)/mLocPolyn3_State_0_0;
   double tmp67_ = tmp38_*tmp21_;
   double tmp68_ = tmp39_*tmp18_;
   double tmp69_ = tmp67_+tmp68_;
   double tmp70_ = (tmp69_)*(tmp17_);
   double tmp71_ = tmp7_*tmp21_;
   double tmp72_ = tmp40_*tmp18_;
   double tmp73_ = tmp71_+tmp72_;
   double tmp74_ = (tmp73_)*(tmp29_);
   double tmp75_ = tmp70_+tmp74_;
   double tmp76_ = tmp2_*tmp18_;
   double tmp77_ = tmp76_*(tmp37_);
   double tmp78_ = tmp75_+tmp77_;
   double tmp79_ = (tmp78_)*(tmp54_);
   double tmp80_ = mCompCoord[2];
   double tmp81_ = tmp79_+tmp80_;
   double tmp82_ = (tmp81_)-mLocPolyn3_State_2_0;
   double tmp83_ = (tmp82_)/mLocPolyn3_State_0_0;
   double tmp84_ = (tmp66_)*(tmp66_);
   double tmp85_ = (tmp83_)*(tmp83_);
   double tmp86_ = mCompCoord[3];
   double tmp87_ = 1+tmp86_;
   double tmp88_ = ElSquare(tmp53_);
   double tmp89_ = (tmp53_)/tmp88_;
   double tmp90_ = ElSquare(mLocPolyn3_State_0_0);
   double tmp91_ = mCompCoord[4];
   double tmp92_ = (tmp89_)*(tmp61_);
   double tmp93_ = tmp92_*mLocPolyn3_State_0_0;
   double tmp94_ = (tmp93_)/tmp90_;
   double tmp95_ = (tmp94_)*(tmp66_);
   double tmp96_ = mCompCoord[5];
   double tmp97_ = tmp96_*2;
   double tmp98_ = (tmp89_)*(tmp78_);
   double tmp99_ = tmp98_*mLocPolyn3_State_0_0;
   double tmp100_ = (tmp99_)/tmp90_;
   double tmp101_ = mCompCoord[6];
   double tmp102_ = (tmp100_)*(tmp83_);
   double tmp103_ = mCompCoord[7];
   double tmp104_ = tmp95_+tmp95_;
   double tmp105_ = mCompCoord[9];
   double tmp106_ = (tmp100_)*(tmp66_);
   double tmp107_ = (tmp94_)*(tmp83_);
   double tmp108_ = (tmp83_)*(tmp66_);
   double tmp109_ = mCompCoord[10];
   double tmp110_ = tmp102_+tmp102_;
   double tmp111_ = mCompCoord[11];
   double tmp112_ = mCompCoord[12];
   double tmp113_ = mLocPolyn3_State_0_0/tmp90_;
   double tmp114_ = (tmp113_)*(tmp66_);
   double tmp115_ = tmp114_+tmp114_;
   double tmp116_ = (tmp113_)*(tmp83_);
   double tmp117_ = tmp116_+tmp116_;
   double tmp118_ = (tmp113_)*tmp85_;
   double tmp119_ = (tmp66_)*(tmp83_);
   double tmp120_ = tmp84_*(tmp66_);
   double tmp121_ = tmp108_*(tmp66_);
   double tmp122_ = tmp85_*(tmp66_);
   double tmp123_ = (tmp83_)*tmp85_;
   double tmp124_ = -(1);
   double tmp125_ = tmp124_*tmp6_;
   double tmp126_ = -(tmp7_);
   double tmp127_ = tmp125_*tmp20_;
   double tmp128_ = tmp126_*tmp19_;
   double tmp129_ = tmp127_*tmp21_;
   double tmp130_ = tmp128_+tmp129_;
   double tmp131_ = (tmp130_)*(tmp17_);
   double tmp132_ = tmp125_*tmp19_;
   double tmp133_ = tmp132_+tmp43_;
   double tmp134_ = (tmp133_)*(tmp29_);
   double tmp135_ = tmp131_+tmp134_;
   double tmp136_ = tmp41_*(tmp135_);
   double tmp137_ = -(tmp136_);
   double tmp138_ = tmp137_/tmp88_;
   double tmp139_ = tmp125_*tmp2_;
   double tmp140_ = tmp139_*(tmp17_);
   double tmp141_ = tmp55_*(tmp29_);
   double tmp142_ = tmp140_+tmp141_;
   double tmp143_ = (tmp142_)*(tmp54_);
   double tmp144_ = (tmp138_)*(tmp61_);
   double tmp145_ = tmp143_+tmp144_;
   double tmp146_ = (tmp145_)*mLocPolyn3_State_0_0;
   double tmp147_ = (tmp146_)/tmp90_;
   double tmp148_ = (tmp147_)*(tmp66_);
   double tmp149_ = tmp126_*tmp21_;
   double tmp150_ = tmp127_*tmp18_;
   double tmp151_ = tmp149_+tmp150_;
   double tmp152_ = (tmp151_)*(tmp17_);
   double tmp153_ = tmp125_*tmp21_;
   double tmp154_ = tmp153_+tmp68_;
   double tmp155_ = (tmp154_)*(tmp29_);
   double tmp156_ = tmp152_+tmp155_;
   double tmp157_ = (tmp156_)*(tmp54_);
   double tmp158_ = (tmp138_)*(tmp78_);
   double tmp159_ = tmp157_+tmp158_;
   double tmp160_ = (tmp159_)*mLocPolyn3_State_0_0;
   double tmp161_ = (tmp160_)/tmp90_;
   double tmp162_ = (tmp161_)*(tmp83_);
   double tmp163_ = tmp148_+tmp148_;
   double tmp164_ = (tmp161_)*(tmp66_);
   double tmp165_ = (tmp147_)*(tmp83_);
   double tmp166_ = tmp162_+tmp162_;
   double tmp167_ = tmp124_*tmp8_;
   double tmp168_ = -(tmp2_);
   double tmp169_ = tmp168_*tmp7_;
   double tmp170_ = tmp168_*tmp6_;
   double tmp171_ = tmp169_*tmp21_;
   double tmp172_ = tmp171_*(tmp17_);
   double tmp173_ = tmp170_*tmp21_;
   double tmp174_ = tmp173_*(tmp29_);
   double tmp175_ = tmp172_+tmp174_;
   double tmp176_ = tmp167_*tmp21_;
   double tmp177_ = tmp176_*(tmp37_);
   double tmp178_ = tmp175_+tmp177_;
   double tmp179_ = tmp41_*(tmp178_);
   double tmp180_ = -(tmp179_);
   double tmp181_ = tmp180_/tmp88_;
   double tmp182_ = tmp167_*tmp7_;
   double tmp183_ = tmp182_*(tmp17_);
   double tmp184_ = tmp167_*tmp6_;
   double tmp185_ = tmp184_*(tmp29_);
   double tmp186_ = tmp183_+tmp185_;
   double tmp187_ = tmp2_*(tmp37_);
   double tmp188_ = tmp186_+tmp187_;
   double tmp189_ = (tmp188_)*(tmp54_);
   double tmp190_ = (tmp181_)*(tmp61_);
   double tmp191_ = tmp189_+tmp190_;
   double tmp192_ = (tmp191_)*mLocPolyn3_State_0_0;
   double tmp193_ = (tmp192_)/tmp90_;
   double tmp194_ = (tmp193_)*(tmp66_);
   double tmp195_ = tmp169_*tmp18_;
   double tmp196_ = tmp195_*(tmp17_);
   double tmp197_ = tmp170_*tmp18_;
   double tmp198_ = tmp197_*(tmp29_);
   double tmp199_ = tmp196_+tmp198_;
   double tmp200_ = tmp167_*tmp18_;
   double tmp201_ = tmp200_*(tmp37_);
   double tmp202_ = tmp199_+tmp201_;
   double tmp203_ = (tmp202_)*(tmp54_);
   double tmp204_ = (tmp181_)*(tmp78_);
   double tmp205_ = tmp203_+tmp204_;
   double tmp206_ = (tmp205_)*mLocPolyn3_State_0_0;
   double tmp207_ = (tmp206_)/tmp90_;
   double tmp208_ = (tmp207_)*(tmp83_);
   double tmp209_ = tmp194_+tmp194_;
   double tmp210_ = (tmp207_)*(tmp66_);
   double tmp211_ = (tmp193_)*(tmp83_);
   double tmp212_ = tmp208_+tmp208_;
   double tmp213_ = -(tmp21_);
   double tmp214_ = tmp124_*tmp18_;
   double tmp215_ = tmp213_*tmp38_;
   double tmp216_ = tmp214_*tmp39_;
   double tmp217_ = tmp215_+tmp216_;
   double tmp218_ = (tmp217_)*(tmp17_);
   double tmp219_ = tmp213_*tmp7_;
   double tmp220_ = tmp214_*tmp40_;
   double tmp221_ = tmp219_+tmp220_;
   double tmp222_ = (tmp221_)*(tmp29_);
   double tmp223_ = tmp218_+tmp222_;
   double tmp224_ = tmp214_*tmp2_;
   double tmp225_ = tmp224_*(tmp37_);
   double tmp226_ = tmp223_+tmp225_;
   double tmp227_ = tmp41_*(tmp226_);
   double tmp228_ = -(tmp227_);
   double tmp229_ = tmp228_/tmp88_;
   double tmp230_ = (tmp229_)*(tmp61_);
   double tmp231_ = tmp230_*mLocPolyn3_State_0_0;
   double tmp232_ = (tmp231_)/tmp90_;
   double tmp233_ = (tmp232_)*(tmp66_);
   double tmp234_ = tmp214_*tmp38_;
   double tmp235_ = tmp21_*tmp39_;
   double tmp236_ = tmp234_+tmp235_;
   double tmp237_ = (tmp236_)*(tmp17_);
   double tmp238_ = tmp214_*tmp7_;
   double tmp239_ = tmp21_*tmp40_;
   double tmp240_ = tmp238_+tmp239_;
   double tmp241_ = (tmp240_)*(tmp29_);
   double tmp242_ = tmp237_+tmp241_;
   double tmp243_ = tmp21_*tmp2_;
   double tmp244_ = tmp243_*(tmp37_);
   double tmp245_ = tmp242_+tmp244_;
   double tmp246_ = (tmp245_)*(tmp54_);
   double tmp247_ = (tmp229_)*(tmp78_);
   double tmp248_ = tmp246_+tmp247_;
   double tmp249_ = (tmp248_)*mLocPolyn3_State_0_0;
   double tmp250_ = (tmp249_)/tmp90_;
   double tmp251_ = (tmp250_)*(tmp83_);
   double tmp252_ = tmp233_+tmp233_;
   double tmp253_ = (tmp250_)*(tmp66_);
   double tmp254_ = (tmp232_)*(tmp83_);
   double tmp255_ = tmp251_+tmp251_;
   double tmp256_ = tmp124_*(tmp44_);
   double tmp257_ = tmp41_*tmp256_;
   double tmp258_ = -(tmp257_);
   double tmp259_ = tmp258_/tmp88_;
   double tmp260_ = tmp124_*tmp55_;
   double tmp261_ = tmp260_*(tmp54_);
   double tmp262_ = (tmp259_)*(tmp61_);
   double tmp263_ = tmp261_+tmp262_;
   double tmp264_ = (tmp263_)*mLocPolyn3_State_0_0;
   double tmp265_ = (tmp264_)/tmp90_;
   double tmp266_ = (tmp265_)*(tmp66_);
   double tmp267_ = tmp124_*(tmp69_);
   double tmp268_ = tmp267_*(tmp54_);
   double tmp269_ = (tmp259_)*(tmp78_);
   double tmp270_ = tmp268_+tmp269_;
   double tmp271_ = (tmp270_)*mLocPolyn3_State_0_0;
   double tmp272_ = (tmp271_)/tmp90_;
   double tmp273_ = (tmp272_)*(tmp83_);
   double tmp274_ = tmp266_+tmp266_;
   double tmp275_ = (tmp272_)*(tmp66_);
   double tmp276_ = (tmp265_)*(tmp83_);
   double tmp277_ = tmp273_+tmp273_;
   double tmp278_ = tmp124_*(tmp48_);
   double tmp279_ = tmp41_*tmp278_;
   double tmp280_ = -(tmp279_);
   double tmp281_ = tmp280_/tmp88_;
   double tmp282_ = tmp124_*tmp57_;
   double tmp283_ = tmp282_*(tmp54_);
   double tmp284_ = (tmp281_)*(tmp61_);
   double tmp285_ = tmp283_+tmp284_;
   double tmp286_ = (tmp285_)*mLocPolyn3_State_0_0;
   double tmp287_ = (tmp286_)/tmp90_;
   double tmp288_ = (tmp287_)*(tmp66_);
   double tmp289_ = tmp124_*(tmp73_);
   double tmp290_ = tmp289_*(tmp54_);
   double tmp291_ = (tmp281_)*(tmp78_);
   double tmp292_ = tmp290_+tmp291_;
   double tmp293_ = (tmp292_)*mLocPolyn3_State_0_0;
   double tmp294_ = (tmp293_)/tmp90_;
   double tmp295_ = (tmp294_)*(tmp83_);
   double tmp296_ = tmp288_+tmp288_;
   double tmp297_ = (tmp294_)*(tmp66_);
   double tmp298_ = (tmp287_)*(tmp83_);
   double tmp299_ = tmp295_+tmp295_;
   double tmp300_ = tmp124_*tmp51_;
   double tmp301_ = tmp41_*tmp300_;
   double tmp302_ = -(tmp301_);
   double tmp303_ = tmp302_/tmp88_;
   double tmp304_ = tmp167_*(tmp54_);
   double tmp305_ = (tmp303_)*(tmp61_);
   double tmp306_ = tmp304_+tmp305_;
   double tmp307_ = (tmp306_)*mLocPolyn3_State_0_0;
   double tmp308_ = (tmp307_)/tmp90_;
   double tmp309_ = (tmp308_)*(tmp66_);
   double tmp310_ = tmp124_*tmp76_;
   double tmp311_ = tmp310_*(tmp54_);
   double tmp312_ = (tmp303_)*(tmp78_);
   double tmp313_ = tmp311_+tmp312_;
   double tmp314_ = (tmp313_)*mLocPolyn3_State_0_0;
   double tmp315_ = (tmp314_)/tmp90_;
   double tmp316_ = (tmp315_)*(tmp83_);
   double tmp317_ = tmp309_+tmp309_;
   double tmp318_ = (tmp315_)*(tmp66_);
   double tmp319_ = (tmp308_)*(tmp83_);
   double tmp320_ = tmp316_+tmp316_;
   double tmp321_ = mLocProjI_x*(tmp44_);
   double tmp322_ = mLocProjI_y*(tmp48_);
   double tmp323_ = tmp321_+tmp322_;
   double tmp324_ = mLocProjI_z*tmp51_;
   double tmp325_ = tmp323_+tmp324_;
   double tmp326_ = tmp41_*(tmp325_);
   double tmp327_ = -(tmp326_);
   double tmp328_ = tmp327_/tmp88_;
   double tmp329_ = mLocProjI_x*tmp55_;
   double tmp330_ = mLocProjI_y*tmp57_;
   double tmp331_ = tmp329_+tmp330_;
   double tmp332_ = mLocProjI_z*tmp8_;
   double tmp333_ = tmp331_+tmp332_;
   double tmp334_ = (tmp333_)*(tmp54_);
   double tmp335_ = (tmp328_)*(tmp61_);
   double tmp336_ = tmp334_+tmp335_;
   double tmp337_ = (tmp336_)*mLocPolyn3_State_0_0;
   double tmp338_ = (tmp337_)/tmp90_;
   double tmp339_ = (tmp338_)*(tmp66_);
   double tmp340_ = mLocProjI_x*(tmp69_);
   double tmp341_ = mLocProjI_y*(tmp73_);
   double tmp342_ = tmp340_+tmp341_;
   double tmp343_ = mLocProjI_z*tmp76_;
   double tmp344_ = tmp342_+tmp343_;
   double tmp345_ = (tmp344_)*(tmp54_);
   double tmp346_ = (tmp328_)*(tmp78_);
   double tmp347_ = tmp345_+tmp346_;
   double tmp348_ = (tmp347_)*mLocPolyn3_State_0_0;
   double tmp349_ = (tmp348_)/tmp90_;
   double tmp350_ = (tmp349_)*(tmp83_);
   double tmp351_ = tmp339_+tmp339_;
   double tmp352_ = (tmp349_)*(tmp66_);
   double tmp353_ = (tmp338_)*(tmp83_);
   double tmp354_ = tmp350_+tmp350_;
   double tmp355_ = mLocProjJ_x*(tmp44_);
   double tmp356_ = mLocProjJ_y*(tmp48_);
   double tmp357_ = tmp355_+tmp356_;
   double tmp358_ = mLocProjJ_z*tmp51_;
   double tmp359_ = tmp357_+tmp358_;
   double tmp360_ = tmp41_*(tmp359_);
   double tmp361_ = -(tmp360_);
   double tmp362_ = tmp361_/tmp88_;
   double tmp363_ = mLocProjJ_x*tmp55_;
   double tmp364_ = mLocProjJ_y*tmp57_;
   double tmp365_ = tmp363_+tmp364_;
   double tmp366_ = mLocProjJ_z*tmp8_;
   double tmp367_ = tmp365_+tmp366_;
   double tmp368_ = (tmp367_)*(tmp54_);
   double tmp369_ = (tmp362_)*(tmp61_);
   double tmp370_ = tmp368_+tmp369_;
   double tmp371_ = (tmp370_)*mLocPolyn3_State_0_0;
   double tmp372_ = (tmp371_)/tmp90_;
   double tmp373_ = (tmp372_)*(tmp66_);
   double tmp374_ = mLocProjJ_x*(tmp69_);
   double tmp375_ = mLocProjJ_y*(tmp73_);
   double tmp376_ = tmp374_+tmp375_;
   double tmp377_ = mLocProjJ_z*tmp76_;
   double tmp378_ = tmp376_+tmp377_;
   double tmp379_ = (tmp378_)*(tmp54_);
   double tmp380_ = (tmp362_)*(tmp78_);
   double tmp381_ = tmp379_+tmp380_;
   double tmp382_ = (tmp381_)*mLocPolyn3_State_0_0;
   double tmp383_ = (tmp382_)/tmp90_;
   double tmp384_ = (tmp383_)*(tmp83_);
   double tmp385_ = tmp373_+tmp373_;
   double tmp386_ = (tmp383_)*(tmp66_);
   double tmp387_ = (tmp372_)*(tmp83_);
   double tmp388_ = tmp384_+tmp384_;
   double tmp389_ = mLocProjK_x*(tmp44_);
   double tmp390_ = mLocProjK_y*(tmp48_);
   double tmp391_ = tmp389_+tmp390_;
   double tmp392_ = mLocProjK_z*tmp51_;
   double tmp393_ = tmp391_+tmp392_;
   double tmp394_ = tmp41_*(tmp393_);
   double tmp395_ = -(tmp394_);
   double tmp396_ = tmp395_/tmp88_;
   double tmp397_ = mLocProjK_x*tmp55_;
   double tmp398_ = mLocProjK_y*tmp57_;
   double tmp399_ = tmp397_+tmp398_;
   double tmp400_ = mLocProjK_z*tmp8_;
   double tmp401_ = tmp399_+tmp400_;
   double tmp402_ = (tmp401_)*(tmp54_);
   double tmp403_ = (tmp396_)*(tmp61_);
   double tmp404_ = tmp402_+tmp403_;
   double tmp405_ = (tmp404_)*mLocPolyn3_State_0_0;
   double tmp406_ = (tmp405_)/tmp90_;
   double tmp407_ = (tmp406_)*(tmp66_);
   double tmp408_ = mLocProjK_x*(tmp69_);
   double tmp409_ = mLocProjK_y*(tmp73_);
   double tmp410_ = tmp408_+tmp409_;
   double tmp411_ = mLocProjK_z*tmp76_;
   double tmp412_ = tmp410_+tmp411_;
   double tmp413_ = (tmp412_)*(tmp54_);
   double tmp414_ = (tmp396_)*(tmp78_);
   double tmp415_ = tmp413_+tmp414_;
   double tmp416_ = (tmp415_)*mLocPolyn3_State_0_0;
   double tmp417_ = (tmp416_)/tmp90_;
   double tmp418_ = (tmp417_)*(tmp83_);
   double tmp419_ = tmp407_+tmp407_;
   double tmp420_ = (tmp417_)*(tmp66_);
   double tmp421_ = (tmp406_)*(tmp83_);
   double tmp422_ = tmp418_+tmp418_;
   double tmp423_ = 1-tmp86_;
   double tmp424_ = tmp107_+tmp106_;
   double tmp425_ = tmp101_*2;
   double tmp426_ = mCompCoord[8];
   double tmp427_ = (tmp104_)*(tmp66_);
   double tmp428_ = (tmp94_)*tmp84_;
   double tmp429_ = tmp427_+tmp428_;
   double tmp430_ = mCompCoord[13];
   double tmp431_ = tmp106_+tmp107_;
   double tmp432_ = (tmp431_)*(tmp66_);
   double tmp433_ = (tmp94_)*tmp108_;
   double tmp434_ = tmp432_+tmp433_;
   double tmp435_ = mCompCoord[14];
   double tmp436_ = (tmp110_)*(tmp66_);
   double tmp437_ = (tmp94_)*tmp85_;
   double tmp438_ = tmp436_+tmp437_;
   double tmp439_ = mCompCoord[15];
   double tmp440_ = (tmp100_)*tmp85_;
   double tmp441_ = (tmp110_)*(tmp83_);
   double tmp442_ = tmp440_+tmp441_;
   double tmp443_ = mCompCoord[16];
   double tmp444_ = (tmp113_)*tmp91_;
   double tmp445_ = (tmp115_)*(tmp66_);
   double tmp446_ = (tmp113_)*tmp84_;
   double tmp447_ = tmp445_+tmp446_;
   double tmp448_ = tmp116_*(tmp66_);
   double tmp449_ = (tmp113_)*tmp108_;
   double tmp450_ = tmp448_+tmp449_;
   double tmp451_ = tmp114_*(tmp66_);
   double tmp452_ = (tmp117_)*(tmp66_);
   double tmp453_ = (tmp117_)*(tmp83_);
   double tmp454_ = tmp118_+tmp453_;
   double tmp455_ = (tmp66_)*mLocPolyn3_State_0_0;
   double tmp456_ = tmp455_*mLocScNorm;
   double tmp457_ = tmp119_*mLocPolyn3_State_0_0;
   double tmp458_ = tmp457_*mLocScNorm;
   double tmp459_ = tmp120_*mLocPolyn3_State_0_0;
   double tmp460_ = tmp459_*mLocScNorm;
   double tmp461_ = tmp121_*mLocPolyn3_State_0_0;
   double tmp462_ = tmp461_*mLocScNorm;
   double tmp463_ = tmp122_*mLocPolyn3_State_0_0;
   double tmp464_ = tmp463_*mLocScNorm;
   double tmp465_ = tmp123_*mLocPolyn3_State_0_0;
   double tmp466_ = tmp465_*mLocScNorm;
   double tmp467_ = tmp165_+tmp164_;
   double tmp468_ = (tmp163_)*(tmp66_);
   double tmp469_ = (tmp147_)*tmp84_;
   double tmp470_ = tmp468_+tmp469_;
   double tmp471_ = tmp164_+tmp165_;
   double tmp472_ = (tmp471_)*(tmp66_);
   double tmp473_ = (tmp147_)*tmp108_;
   double tmp474_ = tmp472_+tmp473_;
   double tmp475_ = (tmp166_)*(tmp66_);
   double tmp476_ = (tmp147_)*tmp85_;
   double tmp477_ = tmp475_+tmp476_;
   double tmp478_ = (tmp161_)*tmp85_;
   double tmp479_ = (tmp166_)*(tmp83_);
   double tmp480_ = tmp478_+tmp479_;
   double tmp481_ = tmp211_+tmp210_;
   double tmp482_ = (tmp209_)*(tmp66_);
   double tmp483_ = (tmp193_)*tmp84_;
   double tmp484_ = tmp482_+tmp483_;
   double tmp485_ = tmp210_+tmp211_;
   double tmp486_ = (tmp485_)*(tmp66_);
   double tmp487_ = (tmp193_)*tmp108_;
   double tmp488_ = tmp486_+tmp487_;
   double tmp489_ = (tmp212_)*(tmp66_);
   double tmp490_ = (tmp193_)*tmp85_;
   double tmp491_ = tmp489_+tmp490_;
   double tmp492_ = (tmp207_)*tmp85_;
   double tmp493_ = (tmp212_)*(tmp83_);
   double tmp494_ = tmp492_+tmp493_;
   double tmp495_ = tmp254_+tmp253_;
   double tmp496_ = (tmp252_)*(tmp66_);
   double tmp497_ = (tmp232_)*tmp84_;
   double tmp498_ = tmp496_+tmp497_;
   double tmp499_ = tmp253_+tmp254_;
   double tmp500_ = (tmp499_)*(tmp66_);
   double tmp501_ = (tmp232_)*tmp108_;
   double tmp502_ = tmp500_+tmp501_;
   double tmp503_ = (tmp255_)*(tmp66_);
   double tmp504_ = (tmp232_)*tmp85_;
   double tmp505_ = tmp503_+tmp504_;
   double tmp506_ = (tmp250_)*tmp85_;
   double tmp507_ = (tmp255_)*(tmp83_);
   double tmp508_ = tmp506_+tmp507_;
   double tmp509_ = tmp276_+tmp275_;
   double tmp510_ = (tmp274_)*(tmp66_);
   double tmp511_ = (tmp265_)*tmp84_;
   double tmp512_ = tmp510_+tmp511_;
   double tmp513_ = tmp275_+tmp276_;
   double tmp514_ = (tmp513_)*(tmp66_);
   double tmp515_ = (tmp265_)*tmp108_;
   double tmp516_ = tmp514_+tmp515_;
   double tmp517_ = (tmp277_)*(tmp66_);
   double tmp518_ = (tmp265_)*tmp85_;
   double tmp519_ = tmp517_+tmp518_;
   double tmp520_ = (tmp272_)*tmp85_;
   double tmp521_ = (tmp277_)*(tmp83_);
   double tmp522_ = tmp520_+tmp521_;
   double tmp523_ = tmp298_+tmp297_;
   double tmp524_ = (tmp296_)*(tmp66_);
   double tmp525_ = (tmp287_)*tmp84_;
   double tmp526_ = tmp524_+tmp525_;
   double tmp527_ = tmp297_+tmp298_;
   double tmp528_ = (tmp527_)*(tmp66_);
   double tmp529_ = (tmp287_)*tmp108_;
   double tmp530_ = tmp528_+tmp529_;
   double tmp531_ = (tmp299_)*(tmp66_);
   double tmp532_ = (tmp287_)*tmp85_;
   double tmp533_ = tmp531_+tmp532_;
   double tmp534_ = (tmp294_)*tmp85_;
   double tmp535_ = (tmp299_)*(tmp83_);
   double tmp536_ = tmp534_+tmp535_;
   double tmp537_ = tmp319_+tmp318_;
   double tmp538_ = (tmp317_)*(tmp66_);
   double tmp539_ = (tmp308_)*tmp84_;
   double tmp540_ = tmp538_+tmp539_;
   double tmp541_ = tmp318_+tmp319_;
   double tmp542_ = (tmp541_)*(tmp66_);
   double tmp543_ = (tmp308_)*tmp108_;
   double tmp544_ = tmp542_+tmp543_;
   double tmp545_ = (tmp320_)*(tmp66_);
   double tmp546_ = (tmp308_)*tmp85_;
   double tmp547_ = tmp545_+tmp546_;
   double tmp548_ = (tmp315_)*tmp85_;
   double tmp549_ = (tmp320_)*(tmp83_);
   double tmp550_ = tmp548_+tmp549_;
   double tmp551_ = tmp353_+tmp352_;
   double tmp552_ = (tmp351_)*(tmp66_);
   double tmp553_ = (tmp338_)*tmp84_;
   double tmp554_ = tmp552_+tmp553_;
   double tmp555_ = tmp352_+tmp353_;
   double tmp556_ = (tmp555_)*(tmp66_);
   double tmp557_ = (tmp338_)*tmp108_;
   double tmp558_ = tmp556_+tmp557_;
   double tmp559_ = (tmp354_)*(tmp66_);
   double tmp560_ = (tmp338_)*tmp85_;
   double tmp561_ = tmp559_+tmp560_;
   double tmp562_ = (tmp349_)*tmp85_;
   double tmp563_ = (tmp354_)*(tmp83_);
   double tmp564_ = tmp562_+tmp563_;
   double tmp565_ = tmp387_+tmp386_;
   double tmp566_ = (tmp385_)*(tmp66_);
   double tmp567_ = (tmp372_)*tmp84_;
   double tmp568_ = tmp566_+tmp567_;
   double tmp569_ = tmp386_+tmp387_;
   double tmp570_ = (tmp569_)*(tmp66_);
   double tmp571_ = (tmp372_)*tmp108_;
   double tmp572_ = tmp570_+tmp571_;
   double tmp573_ = (tmp388_)*(tmp66_);
   double tmp574_ = (tmp372_)*tmp85_;
   double tmp575_ = tmp573_+tmp574_;
   double tmp576_ = (tmp383_)*tmp85_;
   double tmp577_ = (tmp388_)*(tmp83_);
   double tmp578_ = tmp576_+tmp577_;
   double tmp579_ = tmp421_+tmp420_;
   double tmp580_ = (tmp419_)*(tmp66_);
   double tmp581_ = (tmp406_)*tmp84_;
   double tmp582_ = tmp580_+tmp581_;
   double tmp583_ = tmp420_+tmp421_;
   double tmp584_ = (tmp583_)*(tmp66_);
   double tmp585_ = (tmp406_)*tmp108_;
   double tmp586_ = tmp584_+tmp585_;
   double tmp587_ = (tmp422_)*(tmp66_);
   double tmp588_ = (tmp406_)*tmp85_;
   double tmp589_ = tmp587_+tmp588_;
   double tmp590_ = (tmp417_)*tmp85_;
   double tmp591_ = (tmp422_)*(tmp83_);
   double tmp592_ = tmp590_+tmp591_;

  mVal[0] = ((mLocPolyn3_State_1_0+(((tmp87_)*(tmp66_)+tmp91_*(tmp83_))-tmp97_*tmp84_+tmp101_*tmp119_+tmp103_*tmp85_)*mLocPolyn3_State_0_0+(tmp105_*tmp120_+tmp109_*tmp121_+tmp111_*tmp122_+tmp112_*tmp123_)*mLocPolyn3_State_0_0)-mLocXIm)*mLocScNorm;

  mCompDer[0][0] = ((((tmp94_)*(tmp87_)+(tmp100_)*tmp91_)-(tmp104_)*tmp97_+(tmp424_)*tmp101_+(tmp110_)*tmp103_)*mLocPolyn3_State_0_0+((tmp429_)*tmp105_+(tmp434_)*tmp109_+(tmp438_)*tmp111_+(tmp442_)*tmp112_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[0][1] = (((tmp113_)*(tmp87_)-(tmp115_)*tmp97_+tmp116_*tmp101_)*mLocPolyn3_State_0_0+((tmp447_)*tmp105_+(tmp450_)*tmp109_+tmp118_*tmp111_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[0][2] = ((tmp444_+tmp114_*tmp101_+(tmp117_)*tmp103_)*mLocPolyn3_State_0_0+(tmp451_*tmp109_+tmp452_*tmp111_+(tmp454_)*tmp112_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[0][3] = tmp456_;
  mCompDer[0][4] = (tmp83_)*mLocPolyn3_State_0_0*mLocScNorm;
  mCompDer[0][5] = -(2*tmp84_)*mLocPolyn3_State_0_0*mLocScNorm;
  mCompDer[0][6] = tmp458_;
  mCompDer[0][7] = tmp85_*mLocPolyn3_State_0_0*mLocScNorm;
  mCompDer[0][8] = 0;
  mCompDer[0][9] = tmp460_;
  mCompDer[0][10] = tmp462_;
  mCompDer[0][11] = tmp464_;
  mCompDer[0][12] = tmp466_;
  mCompDer[0][13] = 0;
  mCompDer[0][14] = 0;
  mCompDer[0][15] = 0;
  mCompDer[0][16] = 0;
  mCompDer[0][17] = ((((tmp147_)*(tmp87_)+(tmp161_)*tmp91_)-(tmp163_)*tmp97_+(tmp467_)*tmp101_+(tmp166_)*tmp103_)*mLocPolyn3_State_0_0+((tmp470_)*tmp105_+(tmp474_)*tmp109_+(tmp477_)*tmp111_+(tmp480_)*tmp112_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[0][18] = ((((tmp193_)*(tmp87_)+(tmp207_)*tmp91_)-(tmp209_)*tmp97_+(tmp481_)*tmp101_+(tmp212_)*tmp103_)*mLocPolyn3_State_0_0+((tmp484_)*tmp105_+(tmp488_)*tmp109_+(tmp491_)*tmp111_+(tmp494_)*tmp112_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[0][19] = ((((tmp232_)*(tmp87_)+(tmp250_)*tmp91_)-(tmp252_)*tmp97_+(tmp495_)*tmp101_+(tmp255_)*tmp103_)*mLocPolyn3_State_0_0+((tmp498_)*tmp105_+(tmp502_)*tmp109_+(tmp505_)*tmp111_+(tmp508_)*tmp112_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[0][20] = ((((tmp265_)*(tmp87_)+(tmp272_)*tmp91_)-(tmp274_)*tmp97_+(tmp509_)*tmp101_+(tmp277_)*tmp103_)*mLocPolyn3_State_0_0+((tmp512_)*tmp105_+(tmp516_)*tmp109_+(tmp519_)*tmp111_+(tmp522_)*tmp112_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[0][21] = ((((tmp287_)*(tmp87_)+(tmp294_)*tmp91_)-(tmp296_)*tmp97_+(tmp523_)*tmp101_+(tmp299_)*tmp103_)*mLocPolyn3_State_0_0+((tmp526_)*tmp105_+(tmp530_)*tmp109_+(tmp533_)*tmp111_+(tmp536_)*tmp112_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[0][22] = ((((tmp308_)*(tmp87_)+(tmp315_)*tmp91_)-(tmp317_)*tmp97_+(tmp537_)*tmp101_+(tmp320_)*tmp103_)*mLocPolyn3_State_0_0+((tmp540_)*tmp105_+(tmp544_)*tmp109_+(tmp547_)*tmp111_+(tmp550_)*tmp112_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[0][23] = ((((tmp338_)*(tmp87_)+(tmp349_)*tmp91_)-(tmp351_)*tmp97_+(tmp551_)*tmp101_+(tmp354_)*tmp103_)*mLocPolyn3_State_0_0+((tmp554_)*tmp105_+(tmp558_)*tmp109_+(tmp561_)*tmp111_+(tmp564_)*tmp112_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[0][24] = ((((tmp372_)*(tmp87_)+(tmp383_)*tmp91_)-(tmp385_)*tmp97_+(tmp565_)*tmp101_+(tmp388_)*tmp103_)*mLocPolyn3_State_0_0+((tmp568_)*tmp105_+(tmp572_)*tmp109_+(tmp575_)*tmp111_+(tmp578_)*tmp112_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[0][25] = ((((tmp406_)*(tmp87_)+(tmp417_)*tmp91_)-(tmp419_)*tmp97_+(tmp579_)*tmp101_+(tmp422_)*tmp103_)*mLocPolyn3_State_0_0+((tmp582_)*tmp105_+(tmp586_)*tmp109_+(tmp589_)*tmp111_+(tmp592_)*tmp112_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mVal[1] = ((mLocPolyn3_State_2_0+(((tmp423_)*(tmp83_)+tmp91_*(tmp66_)+tmp96_*tmp119_)-tmp425_*tmp85_+tmp426_*tmp84_)*mLocPolyn3_State_0_0+(tmp430_*tmp120_+tmp435_*tmp121_+tmp439_*tmp122_+tmp443_*tmp123_)*mLocPolyn3_State_0_0)-mLocYIm)*mLocScNorm;

  mCompDer[1][0] = ((((tmp100_)*(tmp423_)+(tmp94_)*tmp91_+(tmp424_)*tmp96_)-(tmp110_)*tmp425_+(tmp104_)*tmp426_)*mLocPolyn3_State_0_0+((tmp429_)*tmp430_+(tmp434_)*tmp435_+(tmp438_)*tmp439_+(tmp442_)*tmp443_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[1][1] = ((tmp444_+tmp116_*tmp96_+(tmp115_)*tmp426_)*mLocPolyn3_State_0_0+((tmp447_)*tmp430_+(tmp450_)*tmp435_+tmp118_*tmp439_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[1][2] = ((((tmp113_)*(tmp423_)+tmp114_*tmp96_)-(tmp117_)*tmp425_)*mLocPolyn3_State_0_0+(tmp451_*tmp435_+tmp452_*tmp439_+(tmp454_)*tmp443_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[1][3] = tmp124_*(tmp83_)*mLocPolyn3_State_0_0*mLocScNorm;
  mCompDer[1][4] = tmp456_;
  mCompDer[1][5] = tmp458_;
  mCompDer[1][6] = -(2*tmp85_)*mLocPolyn3_State_0_0*mLocScNorm;
  mCompDer[1][7] = 0;
  mCompDer[1][8] = tmp84_*mLocPolyn3_State_0_0*mLocScNorm;
  mCompDer[1][9] = 0;
  mCompDer[1][10] = 0;
  mCompDer[1][11] = 0;
  mCompDer[1][12] = 0;
  mCompDer[1][13] = tmp460_;
  mCompDer[1][14] = tmp462_;
  mCompDer[1][15] = tmp464_;
  mCompDer[1][16] = tmp466_;
  mCompDer[1][17] = ((((tmp161_)*(tmp423_)+(tmp147_)*tmp91_+(tmp467_)*tmp96_)-(tmp166_)*tmp425_+(tmp163_)*tmp426_)*mLocPolyn3_State_0_0+((tmp470_)*tmp430_+(tmp474_)*tmp435_+(tmp477_)*tmp439_+(tmp480_)*tmp443_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[1][18] = ((((tmp207_)*(tmp423_)+(tmp193_)*tmp91_+(tmp481_)*tmp96_)-(tmp212_)*tmp425_+(tmp209_)*tmp426_)*mLocPolyn3_State_0_0+((tmp484_)*tmp430_+(tmp488_)*tmp435_+(tmp491_)*tmp439_+(tmp494_)*tmp443_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[1][19] = ((((tmp250_)*(tmp423_)+(tmp232_)*tmp91_+(tmp495_)*tmp96_)-(tmp255_)*tmp425_+(tmp252_)*tmp426_)*mLocPolyn3_State_0_0+((tmp498_)*tmp430_+(tmp502_)*tmp435_+(tmp505_)*tmp439_+(tmp508_)*tmp443_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[1][20] = ((((tmp272_)*(tmp423_)+(tmp265_)*tmp91_+(tmp509_)*tmp96_)-(tmp277_)*tmp425_+(tmp274_)*tmp426_)*mLocPolyn3_State_0_0+((tmp512_)*tmp430_+(tmp516_)*tmp435_+(tmp519_)*tmp439_+(tmp522_)*tmp443_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[1][21] = ((((tmp294_)*(tmp423_)+(tmp287_)*tmp91_+(tmp523_)*tmp96_)-(tmp299_)*tmp425_+(tmp296_)*tmp426_)*mLocPolyn3_State_0_0+((tmp526_)*tmp430_+(tmp530_)*tmp435_+(tmp533_)*tmp439_+(tmp536_)*tmp443_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[1][22] = ((((tmp315_)*(tmp423_)+(tmp308_)*tmp91_+(tmp537_)*tmp96_)-(tmp320_)*tmp425_+(tmp317_)*tmp426_)*mLocPolyn3_State_0_0+((tmp540_)*tmp430_+(tmp544_)*tmp435_+(tmp547_)*tmp439_+(tmp550_)*tmp443_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[1][23] = ((((tmp349_)*(tmp423_)+(tmp338_)*tmp91_+(tmp551_)*tmp96_)-(tmp354_)*tmp425_+(tmp351_)*tmp426_)*mLocPolyn3_State_0_0+((tmp554_)*tmp430_+(tmp558_)*tmp435_+(tmp561_)*tmp439_+(tmp564_)*tmp443_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[1][24] = ((((tmp383_)*(tmp423_)+(tmp372_)*tmp91_+(tmp565_)*tmp96_)-(tmp388_)*tmp425_+(tmp385_)*tmp426_)*mLocPolyn3_State_0_0+((tmp568_)*tmp430_+(tmp572_)*tmp435_+(tmp575_)*tmp439_+(tmp578_)*tmp443_)*mLocPolyn3_State_0_0)*mLocScNorm;
  mCompDer[1][25] = ((((tmp417_)*(tmp423_)+(tmp406_)*tmp91_+(tmp579_)*tmp96_)-(tmp422_)*tmp425_+(tmp419_)*tmp426_)*mLocPolyn3_State_0_0+((tmp582_)*tmp430_+(tmp586_)*tmp435_+(tmp589_)*tmp439_+(tmp592_)*tmp443_)*mLocPolyn3_State_0_0)*mLocScNorm;
}


void cEqAppui_PProjInc_M2CPolyn3::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqAppui_PProjInc_M2CPolyn3 Has no Der Sec");
}

void cEqAppui_PProjInc_M2CPolyn3::SetPolyn3_State_0_0(double aVal){ mLocPolyn3_State_0_0 = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetPolyn3_State_1_0(double aVal){ mLocPolyn3_State_1_0 = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetPolyn3_State_2_0(double aVal){ mLocPolyn3_State_2_0 = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjI_x(double aVal){ mLocProjI_x = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjI_y(double aVal){ mLocProjI_y = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjI_z(double aVal){ mLocProjI_z = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjJ_x(double aVal){ mLocProjJ_x = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjJ_y(double aVal){ mLocProjJ_y = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjJ_z(double aVal){ mLocProjJ_z = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjK_x(double aVal){ mLocProjK_x = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjK_y(double aVal){ mLocProjK_y = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjK_z(double aVal){ mLocProjK_z = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjP0_x(double aVal){ mLocProjP0_x = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjP0_y(double aVal){ mLocProjP0_y = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetProjP0_z(double aVal){ mLocProjP0_z = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetScNorm(double aVal){ mLocScNorm = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetXIm(double aVal){ mLocXIm = aVal;}
void cEqAppui_PProjInc_M2CPolyn3::SetYIm(double aVal){ mLocYIm = aVal;}



double * cEqAppui_PProjInc_M2CPolyn3::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "Polyn3_State_0_0") return & mLocPolyn3_State_0_0;
   if (aName == "Polyn3_State_1_0") return & mLocPolyn3_State_1_0;
   if (aName == "Polyn3_State_2_0") return & mLocPolyn3_State_2_0;
   if (aName == "ProjI_x") return & mLocProjI_x;
   if (aName == "ProjI_y") return & mLocProjI_y;
   if (aName == "ProjI_z") return & mLocProjI_z;
   if (aName == "ProjJ_x") return & mLocProjJ_x;
   if (aName == "ProjJ_y") return & mLocProjJ_y;
   if (aName == "ProjJ_z") return & mLocProjJ_z;
   if (aName == "ProjK_x") return & mLocProjK_x;
   if (aName == "ProjK_y") return & mLocProjK_y;
   if (aName == "ProjK_z") return & mLocProjK_z;
   if (aName == "ProjP0_x") return & mLocProjP0_x;
   if (aName == "ProjP0_y") return & mLocProjP0_y;
   if (aName == "ProjP0_z") return & mLocProjP0_z;
   if (aName == "ScNorm") return & mLocScNorm;
   if (aName == "XIm") return & mLocXIm;
   if (aName == "YIm") return & mLocYIm;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqAppui_PProjInc_M2CPolyn3::mTheAuto("cEqAppui_PProjInc_M2CPolyn3",cEqAppui_PProjInc_M2CPolyn3::Alloc);


cElCompiledFonc *  cEqAppui_PProjInc_M2CPolyn3::Alloc()
{  return new cEqAppui_PProjInc_M2CPolyn3();
}



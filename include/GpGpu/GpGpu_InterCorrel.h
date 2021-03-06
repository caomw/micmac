#ifndef __GPGPU_intERCORREL_H__
#define __GPGPU_intERCORREL_H__

#ifdef _WIN32
    #ifdef int
        #undef int
    #endif
#endif

#include "GpGpu/GpGpu.h"

#if CUDA_ENABLED

#ifndef BOOST_ALL_NO_LIB
    #define BOOST_ALL_NO_LIB
#endif

#include "GpGpu/GpGpu_MultiThreadingCpu.h"
#include "GpGpu/SData2Correl.h"

extern "C" void	CopyParamTodevice(pCorGpu h);
extern "C" void CopyParamInvTodevice( pCorGpu param );
extern "C" void	LaunchKernelCorrelation(const int s,cudaStream_t stream,pCorGpu &param,SData2Correl &dataCorrel);
extern "C" void	LaunchKernelMultiCorrelation(cudaStream_t stream, pCorGpu &param, SData2Correl &dataCorrel);

extern "C" void dilateKernel(pixel* HostDataOut, short r, uint2 dim);
extern "C" void	LaunchKernelprojectionImage(pCorGpu &param,CuDeviceData3D<float>  &DeviImagesProj);

/// \class GpGpuInterfaceCorrel
/// \brief Class qui lie micmac avec les outils de calculs GpGpu
class GpGpuInterfaceCorrel : public CSimpleJobCpuGpu< bool>
{

public:

  GpGpuInterfaceCorrel();
  ~GpGpuInterfaceCorrel();

  /// \brief    Initialise les parametres de correlation
  void          SetParameter(int nbLayer , ushort2 dRVig , uint2 dimImg, float mAhEpsilon, uint samplingZ, int uvintDef, ushort nClass);

  /// \brief    Calcul de la correlation en Gpu
  void          BasicCorrelation();

  /// \brief    Renvoie les parametres de correlation

  pCorGpu&      Param(ushort idBuf);

  void          signalComputeCorrel(uint dZ);

  ///
  /// \brief InitCorrelJob initialise le job
  /// \param Zmin z minimum
  /// \param Zmax z minimum
  /// \return
  ///
  uint          InitCorrelJob(int Zmin, int Zmax);

  void          freezeCompute();

  void          IntervalZ(uint &interZ, int anZProjection, int aZMaxTer);

  SData2Correl& Data();

  float*        VolumeCost(ushort id);

  bool          TexturesAreLoaded();

  void          SetTexturesAreLoaded(bool load);  

  void          ReallocHostData(uint interZ, ushort idBuff);

  uint2&        DimTerrainGlob();

  std::vector<cellules> &MaskVolumeBlock();

  bool              NoMasked;

private:

  void              CorrelationGpGpu(ushort idBuf = 0 , const int s = 0);

  void              MultiCorrelationGpGpu(ushort idBuf = 0,const int s = 0);

  cudaStream_t*		GetStream(int stream);

  void              simpleWork();

  cudaStream_t      _stream[NSTREAM];

  pCorGpu           _param[2];

  SData2Correl      _data2Cor;

  bool				_TexturesAreLoaded;

  uint2             _m_DimTerrainGlob;

  std::vector<cellules> _m_MaskVolumeBlock;

  bool              copyInvParam;


};

#endif

#endif // __GPGPU_intERCORREL_H__

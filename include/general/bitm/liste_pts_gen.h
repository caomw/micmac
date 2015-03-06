#ifndef _ELISE_GENERAL_BITM_LISTE_PTS_GEN_H
#define _ELISE_GENERAL_BITM_LISTE_PTS_GEN_H

#include "general/sys_dep.h"

class Liste_Pts_Gen :  public PRC0
{
      friend class Output;
      protected :
          Liste_Pts_Gen(Data_Liste_Pts_Gen *);
      public :
          Flux_Pts  all_pts();
          bool      empty() const;
          int       card() const;
          int       dim() const;
};

#endif

/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 * File: udptest.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 03-Oct-2022 14:36:39
 */

/* Include Files */
#include "udptest.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <stdio.h>

/* Function Definitions */
/*
 * #codegen
 *
 * Arguments    : void
 * Return Type  : void
 */
void udptest(void)
{
  double udp_cSFunObject_W0_NetworkLib[137];
  int samplesRead;
  int udp_isInitialized;
  unsigned char udp_cSFunObject_O0_Y0_data[255];
  char *sErr;
  udp_isInitialized = 0;
  /* System object Constructor function: dsp.UDPReceiver */
  while (1) {
    int c_udp_cSFunObject_O0_Y0_size_id;
    if (udp_isInitialized != 1) {
      udp_isInitialized = 1;
      /* System object Start function: dsp.UDPReceiver */
      sErr = GetErrorBuffer(&udp_cSFunObject_W0_NetworkLib[0U]);
      CreateUDPInterface(&udp_cSFunObject_W0_NetworkLib[0U]);
      if (*sErr == 0) {
        LibCreate_Network(&udp_cSFunObject_W0_NetworkLib[0U], 0, "0.0.0.0",
                          20000, "0.0.0.0", -1, 8192, 1, 0);
      }
      if (*sErr == 0) {
        LibStart(&udp_cSFunObject_W0_NetworkLib[0U]);
      }
      if (*sErr != 0) {
        DestroyUDPInterface(&udp_cSFunObject_W0_NetworkLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
      }
    }
    /* System object Outputs function: dsp.UDPReceiver */
    sErr = GetErrorBuffer(&udp_cSFunObject_W0_NetworkLib[0U]);
    samplesRead = 255;
    LibOutputs_Network(&udp_cSFunObject_W0_NetworkLib[0U],
                       &udp_cSFunObject_O0_Y0_data[0U], &samplesRead);
    if (*sErr != 0) {
      PrintError(sErr);
    }
    c_udp_cSFunObject_O0_Y0_size_id = samplesRead;
    if ((unsigned char)c_udp_cSFunObject_O0_Y0_size_id != 0) {
      printf("Data len %d\n",
             (int)(unsigned char)c_udp_cSFunObject_O0_Y0_size_id);
      fflush(stdout);
    }
  }
}

/*
 * File trailer for udptest.c
 *
 * [EOF]
 */

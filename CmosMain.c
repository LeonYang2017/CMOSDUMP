#include <Efi.h>
#include <AmiDxeLib.h>
#include <Protocol/SmbiosDynamicData.h>
#include <Protocol/SmBus.h>
#include <Protocol/AmiSmbios.h>
#include <Uefi.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/PrintLib.h>
#include <Guid/GlobalVariable.h>
#include <Protocol/Shell.h>
#include <Protocol/Smbios.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/BaseMemoryLib/MemLibInternals.h>



/**
  CMOS Dump Entry point

  @param[in]  ImageHandle     The image handle.
  @param[in]  SystemTable     The system table.

  @retval EFI_SUCCESS            Command completed successfully.
  @retval EFI_INVALID_PARAMETER  Command usage error.
  @retval EFI_NOT_FOUND          The input file can't be found.
**/
EFI_STATUS
EFIAPI
CMOSDumpEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
//      EFI_STATUS                            Status;
//      EFI_HANDLE                            *Handles;
      UINT8                                 F0[16]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
      UINT8                                 F1[16]={0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F};
      UINT8                                 F2[16]={0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F};
      UINT8                                 F3[16]={0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F};
      UINT8                                 F4[16]={0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F};
      UINT8                                 F5[16]={0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F};
      UINT8                                 F6[16]={0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F};
      UINT8                                 F7[16]={0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F};
      UINT8                                 F8[16]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F};
      UINT8                                 F9[16]={0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F};
      UINT8                                 FA[16]={0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF};
      UINT8                                 FB[16]={0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF};
      UINT8                                 FC[16]={0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF};
      UINT8                                 FD[16]={0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF};
      UINT8                                 FE[16]={0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF};
      UINT8                                 FF[16]={0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF};
      UINT8                                 i = 0;
      UINT8                                 Data = 0;
      
      Print(L"Dump CMOS data as follow:\n");
      Print(L"   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n");
      Print(L"0: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,F0[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");
      
      Print(L"1: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,F1[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");
      
      Print(L"2: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,F2[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"3: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,F3[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"4: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,F4[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"5: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,F5[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"6: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,F6[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"7: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,F7[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"8: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,F8[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"9: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,F9[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"A: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,FA[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");


      Print(L"B: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,FB[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"C: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,FC[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"D: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,FD[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"E: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,FE[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      Print(L"F: ");
      for(i=0;i<16;i++){
          IoWrite8(0x70,FF[i]);
          Data = IoRead8 (0x71);
          if(Data <= 0x0F){
            Print(L"0");
          }
          Print(L"%X ",Data);
      }
      Print(L"\n");

      return 0;
}

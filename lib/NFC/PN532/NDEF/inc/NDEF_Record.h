/*!
 * @file  NDEF_Record.h
 * @brief
 * ----------
 * Adapted code from Seeed Studio PN532 driver for Arduino.
 * You can find the Seeed Studio PN532 driver here: https://github.com/Seeed-Studio/PN532
 * ----------
 * NXP PN532 Data Sheet:  https://www.nxp.com/docs/en/nxp/data-sheets/PN532_C1.pdf
 * NXP PN532 User Manual: https://www.nxp.com/docs/en/user-guide/141520.pdf
 * ----------
 * For future development and updates, please follow this repository: https://github.com/ZeeLivermorium/PN532_TM4C123
 * ----------
 * If you find any bug or problem, please create new issue or a pull request with a fix in the repository.
 * Or you can simply email me about the problem or bug at zeelivermorium@gmail.com
 * Much Appreciated!
 * ----------
 * @author Zee Livermorium
 * @date Nov 13, 2018
 */

#ifndef __NDEF_RECORD_H__
#define __NDEF_RECORD_H__

#include <stdint.h>
//#include <Ndef.h>

#define TNF_EMPTY         0x0
#define TNF_WELL_KNOWN    0x01
#define TNF_MIME_MEDIA    0x02
#define TNF_ABSOLUTE_URI  0x03
#define TNF_EXTERNAL_TYPE 0x04
#define TNF_UNKNOWN       0x05
#define TNF_UNCHANGED     0x06
#define TNF_RESERVED      0x07

typedef struct _NDEF_Record {
    uint8_t  tnf;
    uint32_t type_length;
    uint32_t payload_length;
    uint32_t id_length;
    char*    type;
    char*    payload;
    char*    id;
} NDEF_Record;

void NDEF_Record_encode (
                         NDEF_Record ndef_record,
                         uint8_t* data_buffer,
                         uint8_t first_record,
                         uint8_t last_record
                         );

//void print();

uint8_t encodeHeader (
                      NDEF_Record ndef_record,
                      uint8_t first_record,
                      uint8_t last_record
                      );

uint32_t NDEF_Record_getEncodedSize (NDEF_Record ndef_record);



#endif


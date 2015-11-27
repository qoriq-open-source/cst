/* Copyright (c) 2015 Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Freescale Semiconductor nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _PARSE_UTILS_H
#define _PARSE_UTILS_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>
#include <netinet/in.h>

#include <global.h>

#define MAX_LINE_SIZE		1024
#define MAX_U32			0xFFFFFFFF

struct input_field {
	char *value[64];
	int count;
};

unsigned long STR_TO_UL(char *str, int base);
unsigned long long STR_TO_ULL(char *str, int base);
void find_value_from_file(char *field_name, FILE *fp);
int fill_gd_input_file(char *field_name, FILE *fp);
int get_file_size(const char *file_name);

enum input_field_t {
	FIELD_PLATFORM = 0,
	FIELD_ENTRY_POINT,
	FIELD_PUB_KEY,
	FIELD_KEY_SELECT,
	FIELD_IMAGE_1,
	FIELD_IMAGE_2,
	FIELD_IMAGE_3,
	FIELD_IMAGE_4,
	FIELD_IMAGE_5,
	FIELD_IMAGE_6,
	FIELD_IMAGE_7,
	FIELD_IMAGE_8,
	FIELD_FSL_UID_0,
	FIELD_FSL_UID_1,
	FIELD_OEM_UID_0,
	FIELD_OEM_UID_1,
	FIELD_OEM_UID_2,
	FIELD_OEM_UID_3,
	FIELD_OEM_UID_4,
	FIELD_OUTPUT_HDR_FILENAME,
	FIELD_MP_FLAG,
	FIELD_ISS_FLAG,
	FIELD_LW_FLAG,
	FIELD_VERBOSE,
	FIELD_PRI_KEY,
	FIELD_IMAGE_HASH_FILENAME,
	FIELD_RSA_SIGN_FILENAME,
	FIELD_RCW_PBI_FILENAME,
	FIELD_BOOT1_PTR,
	FIELD_SEC_IMAGE,
	FIELD_WP_FLAG,
	FIELD_HK_AREA_POINTER,
	FIELD_HK_AREA_SIZE,
	FIELD_IMAGE_TARGET,
	FIELD_UNKNOWN_MAX
};

typedef struct {
	char *field_name;
	enum input_field_t index;
} parse_struct_t;

typedef union {
	uint64_t whole;
	struct {
		uint32_t low;
		uint32_t high;
	} m_halfs;
} DWord;

#endif

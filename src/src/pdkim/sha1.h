/**
 * \file sha1.h
 *
 *  Copyright (C) 2006-2009, Paul Bakker <polarssl_maintainer at polarssl.org>
 *  All rights reserved.
 *
 *  Joined copyright on original XySSL code with: Christophe Devine
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* $Cambridge: exim/src/src/pdkim/sha1.h,v 1.3 2009/12/07 13:05:07 tom Exp $ */

#ifndef POLARSSL_SHA1_H
#define POLARSSL_SHA1_H

/**
 * \brief          SHA-1 context structure
 */

#ifndef HAVE_SHA1_CONTEXT
#define HAVE_SHA1_CONTEXT
typedef struct sha1_context sha1_context;
#endif

struct sha1_context
{
    unsigned long total[2];     /*!< number of bytes processed  */
    unsigned long state[5];     /*!< intermediate digest state  */
    unsigned char buffer[64];   /*!< data block being processed */

    unsigned char ipad[64];     /*!< HMAC: inner padding        */
    unsigned char opad[64];     /*!< HMAC: outer padding        */
};


#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief          SHA-1 context setup
 *
 * \param ctx      context to be initialized
 */
void sha1_starts( sha1_context *ctx );

/**
 * \brief          SHA-1 process buffer
 *
 * \param ctx      SHA-1 context
 * \param input    buffer holding the  data
 * \param ilen     length of the input data
 */
void sha1_update( sha1_context *ctx, unsigned char *input, int ilen );

/**
 * \brief          SHA-1 final digest
 *
 * \param ctx      SHA-1 context
 * \param output   SHA-1 checksum result
 */
void sha1_finish( sha1_context *ctx, unsigned char output[20] );

/**
 * \brief          Output = SHA-1( input buffer )
 *
 * \param input    buffer holding the  data
 * \param ilen     length of the input data
 * \param output   SHA-1 checksum result
 */
void sha1( unsigned char *input, int ilen, unsigned char output[20] );

/**
 * \brief          Output = SHA-1( file contents )
 *
 * \param path     input file name
 * \param output   SHA-1 checksum result
 *
 * \return         0 if successful, 1 if fopen failed,
 *                 or 2 if fread failed
 */
int sha1_file( char *path, unsigned char output[20] );

/**
 * \brief          SHA-1 HMAC context setup
 *
 * \param ctx      HMAC context to be initialized
 * \param key      HMAC secret key
 * \param keylen   length of the HMAC key
 */
void sha1_hmac_starts( sha1_context *ctx, unsigned char *key, int keylen );

/**
 * \brief          SHA-1 HMAC process buffer
 *
 * \param ctx      HMAC context
 * \param input    buffer holding the  data
 * \param ilen     length of the input data
 */
void sha1_hmac_update( sha1_context *ctx, unsigned char *input, int ilen );

/**
 * \brief          SHA-1 HMAC final digest
 *
 * \param ctx      HMAC context
 * \param output   SHA-1 HMAC checksum result
 */
void sha1_hmac_finish( sha1_context *ctx, unsigned char output[20] );

/**
 * \brief          Output = HMAC-SHA-1( hmac key, input buffer )
 *
 * \param key      HMAC secret key
 * \param keylen   length of the HMAC key
 * \param input    buffer holding the  data
 * \param ilen     length of the input data
 * \param output   HMAC-SHA-1 result
 */
void sha1_hmac( unsigned char *key, int keylen,
                unsigned char *input, int ilen,
                unsigned char output[20] );

#ifdef __cplusplus
}
#endif

#endif /* sha1.h */

/*
 * Copyright (c) 2010-2011,2013 Apple Inc. All Rights Reserved.
 * 
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

/*!
 @header SecEncryptTransform

 This file defines a SecTransform that will do both asynchronous and synchronous
 encryption.
 
 The key that is supplied to the SecTransform determines the type of encryption
 to be used.
 
 */
#if !defined(__SEC_ENCRYPT_TRANSFORM__)
#define __SEC_ENCRYPT_TRANSFORM__ 1

#include <CoreFoundation/CoreFoundation.h>
#include <Security/SecKey.h>
#include <Security/SecTransform.h>

#ifdef __cplusplus
extern "C" {
#endif

CF_ASSUME_NONNULL_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED

	/*! @abstract Indicates that no padding will be used when encrypting or decrypting. */
	extern const CFStringRef kSecPaddingNoneKey
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	/*! Indicates that PKCS1 padding will be used when encrypting or decrypting. */
	extern const CFStringRef kSecPaddingPKCS1Key
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	/*! Indicates that PKCS5 padding will be used when encrypting or decrypting. */
	extern const CFStringRef kSecPaddingPKCS5Key
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	/*! Indicates that PKCS7 padding will be used when encrypting or decrypting. */
	extern const CFStringRef kSecPaddingPKCS7Key
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
    /*! Indicates that PKCS7 padding will be used when encrypting or decrypting. */
    extern const CFStringRef kSecPaddingOAEPKey
    API_DEPRECATED("SecTransform is no longer supported", macos(10.8, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	/*! Indicates that no mode will be used when encrypting or decrypting. */
	extern const CFStringRef kSecModeNoneKey
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	/*! Indicates that ECB mode will be used when encrypting or decrypting. */
	extern const CFStringRef kSecModeECBKey
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
    /*! Indicates that CBC mode will be used when encrypting or decrypting. */
	extern const CFStringRef kSecModeCBCKey
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	/*! Indicates that CFB mode will be used when encrypting or decrypting. */
	extern const CFStringRef kSecModeCFBKey
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	/*! Indicates that OFB mode will be used when encrypting or decrypting. */
	extern const CFStringRef kSecModeOFBKey
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	
	/*!
	    @abstract
		This attribute holds the encryption key for the transform. (ReadOnly)
	 */
	extern const CFStringRef kSecEncryptKey
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);

	/*!
	    @abstract
		Key for setting padding.
	    @discussion
		This key is optional.  If you do not supply a value for this key,
	 	an appropriate value will be supplied for you.
	*/
	extern const CFStringRef kSecPaddingKey
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);

	/*!
	    @abstract
		Key for setting an initialization vector.
	    @discussion
		This key is optional.  If you do not supply a
	 	value for this key, an appropriate value will be supplied for you.
	*/
	extern const CFStringRef kSecIVKey
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);

	/*!
     @abstract
     Specifies the encryption mode.
     @discussion
     This key is optional.  If you do not supply this key,
     an appropriate value will be supplied for you.
     */
	extern const CFStringRef kSecEncryptionMode
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	
	/*!
     @abstract
     Specifies the OAEP message length.
     @discussion
     This should be set to a CFNumberRef when the padding is set to OAEP,
     and a specific messages size is desired.   If unset the minimum padding
     will be added.   It is ignored when the padding mode is not OAEP.
     */
	extern const CFStringRef kSecOAEPMessageLengthAttributeName
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	/*!
     @abstract
     Specifies the OAEP encoding paramaters
     @discussion
     This should be set to a CFDataRef when the padding is set to OAEP.
     If unset a zero length CFDataRef is used.   It is ignored by non
     OAEP padding modes.
     */
    extern const CFStringRef kSecOAEPEncodingParametersAttributeName
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	/*!
     @abstract
     Specifies the OAEP MGF1 digest algorithm.
     @discussion
     This should be set to a digest algorithm when the padding is set to OAEP.
     If unset SHA1 is used.   It is ifnored by non OAEP padding modes.
     */
    extern const CFStringRef kSecOAEPMGF1DigestAlgorithmAttributeName
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);

	/*!
	 @function SecEncryptTransformCreate
	 @abstract			Creates an encryption SecTransform  object.
	 @param keyRef			The key for the encryption operation
	 @param error		A pointer to a CFErrorRef.  This pointer will be set
	 if an error occurred.  This value may be NULL if you
	 do not want an error returned.
	 @result				A pointer to a SecTransformRef object.  This object must
	 be released with CFRelease when you are done with
	 it.  This function will return NULL if an error
	 occurred.
	 @discussion			This function creates a transform which encrypts data.
	 */
	
	SecTransformRef SecEncryptTransformCreate(SecKeyRef keyRef,
											  CFErrorRef* error)
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	
	/*!
	 @function SecDecryptTransformCreate
	 @abstract			Creates an encryption SecTransform  object.
	 @param keyRef			The key for the operation
	 @param error		A pointer to a CFErrorRef.  This pointer will be set
	 if an error occurred.  This value may be NULL if you
	 do not want an error returned.
	 @result				A pointer to a SecTransformRef object.  This object must
	 be released with CFRelease when you are done with
	 it.  This function will return NULL if an error
	 occurred.
	 @discussion			This function creates a transform which encrypts data.
	 */
	
	SecTransformRef SecDecryptTransformCreate(SecKeyRef keyRef,
											  CFErrorRef* error)
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);
	
/*!
	@function SecDecryptTransformGetTypeID
	@abstract			Returns the CFTypeID for a decrypt transform.
	@return			the CFTypeID
*/

    CFTypeID SecDecryptTransformGetTypeID(void)
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);

/*!
	@function SecEncryptTransformGetTypeID
	@abstract			Returns the CFTypeID for a decrypt transform.
	@return			the CFTypeID
*/

    CFTypeID SecEncryptTransformGetTypeID(void)
    API_DEPRECATED("SecTransform is no longer supported", macos(10.7, 13.0)) API_UNAVAILABLE(ios, tvos, watchos, macCatalyst);

CF_IMPLICIT_BRIDGING_DISABLED
CF_ASSUME_NONNULL_END

#ifdef __cplusplus
};
#endif

#endif /* ! __SEC_ENCRYPT_TRANSFORM__ */

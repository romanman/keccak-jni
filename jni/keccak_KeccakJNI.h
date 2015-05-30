/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class keccak_KeccakJNI */

#ifndef _Included_keccak_KeccakJNI
#define _Included_keccak_KeccakJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     keccak_KeccakJNI
 * Method:    keccak_sha3
 * Signature: ([B)[B
 */
JNIEXPORT jbyteArray JNICALL Java_keccak_KeccakJNI_keccak_1sha3
  (JNIEnv *, jclass, jbyteArray);

/*
 * Class:     keccak_KeccakJNI
 * Method:    keccak_sha3_2
 * Signature: (Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;I)V
 */
JNIEXPORT void JNICALL Java_keccak_KeccakJNI_keccak_1sha3_12
  (JNIEnv *, jclass, jobject, jobject, jint);

#ifdef __cplusplus
}
#endif
#endif

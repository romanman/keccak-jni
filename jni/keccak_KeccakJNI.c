#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include "keccak_KeccakJNI.h"

#include "sph_keccak.h"


JNIEXPORT void JNICALL Java_keccak_KeccakJNI_keccak_1sha3_12
  (JNIEnv *env, jobject thisObj, jobject input, jobject output, jint size){

   jbyte* dInput = (*env)->GetDirectBufferAddress(env, input);
   jbyte* dOutput = (*env)->GetDirectBufferAddress(env, output);


   sph_keccak256_context mc;

   sph_keccak256_init(&mc);

   sph_keccak256(&mc, dInput, size);
   sph_keccak256_close(&mc, dOutput);
}




JNIEXPORT jbyteArray JNICALL Java_keccak_KeccakJNI_keccak_1sha3(JNIEnv *env, jobject thisObj, jbyteArray input)
{

   jsize size = (*env) -> GetArrayLength (env, input);
   unsigned char *myInput;
   myInput = malloc(1 + size);

   (*env) -> GetByteArrayRegion (env, input, 0, size, myInput);

   sph_keccak256_context mc;
   unsigned char *res = malloc(32);
   size_t dbuf_len;
   unsigned char *dbuf;

   sph_keccak256_init(&mc);
   sph_keccak256(&mc, myInput, size);
   sph_keccak256_close(&mc, res);

  jbyteArray jbyteResult = (*env) -> NewByteArray(env, 32);
   (*env) -> SetByteArrayRegion (env, jbyteResult, 0, 32, (jbyte*)res);

  free(myInput);
  free(res);
  return jbyteResult;
}




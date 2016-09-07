= Ported Algorithms =


== Hash Algorithms ==

  - SHA1
  - MD5
  
== Encryption Algorithms ==

  - AES

= Changes from AVR-Crypto-Lib = 
  
  - Added a `common` folder for common sources and portable assembly files. 

  - Suppressed all DEBUG from the original implementation. Intent is to provide 
    integration with the HAL's bc_iface in the future. Removed the following 
    'common' header files :
      - `config.h`
      - `cli.h`
      - `debug.h`
    In their place, created a (currently blank) dummy holder for debug functions 
    in `common/debug.h`. 
  
  - Moved `avr_asm_macros.S` into `common`.
  
  - Renamed all used assembly sources from `*-asm.S` to `*-avr.S`. CMakeLists 
    designed to now use `<name>-<toolchain-prefix>.S` when told to include 
    `<name>.c`, if 
      - the assembly file is available.
      - the CMake variable `USE_ASM_IF_AVAILABLE` is set.
      - where the build system is configured with a toolchain file that sets
        the CMake TOOLCHAIN_PREFIX variable. Note that this variable was 
        intended to recognize toolchain binaries, such as "avr-gcc" (with a 
        TOOLCHAIN_PREFIX of 'avr') and "msp430-elf-gcc" (with a TOOLCHAIN_PREFIX 
        of 'msp430-elf'). Assembly files must therefore be named accordingly.
  
  - Moved tables from `PROGMEM` into the newly defined `ROMEM` of 
    `common/romem.h`. This header should, in principle, be able to handle 
    differences in how each platform handles read only memory. This has not 
    yet been adequately tested.
    
== AES ==

  - Moved all the `aesXXX_enc.h/c` files into `aes_enc.h/c`. This makes it 
    compatible with the structure of `aes_enc-avr.S`.
    
  - Moved all the `aesXXX_dec.h/c` files into `aes_dec.h/c`. This makes it 
    compatible with the structure of `aes_dec-avr.S`.
  
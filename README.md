[Original Readme](README.rst)

# QEMU for REITO

Add REITO support in RISC-V target

## Compiling

Ubuntu 20.04:
```
sudo apt-get install git libglib2.0-dev libfdt-dev libpixman-1-dev zlib1g-dev ninja-build git-email libaio-dev libbluetooth-dev libcapstone-dev libbrlapi-dev libbz2-dev libcap-ng-dev libcurl4-gnutls-dev libgtk-3-dev libibverbs-dev libjpeg8-dev libncurses5-dev libnuma-dev librbd-dev librdmacm-dev libsasl2-dev libsdl2-dev libseccomp-dev libsnappy-dev libssh-dev libvde-dev libvdeplug-dev libvte-2.91-dev libxen-dev liblzo2-dev valgrind xfslibs-dev libnfs-dev libiscsi-dev
mkdir build
cd build
../configure --prefix=/home/reito/reito-qemu --target-list=riscv32-softmmu,riscv64-softmmu
make -j33
``` 

## Modifications

- Add decode file to `meson.build`
``` 
decodetree.process('XReito.decode', extra_args: '--static-decode=decode_XReito'),
```

- Add things to `cpu.h`
```
bool ext_XReito;
```

- Add things to `cpu.c`
```
DEFINE_PROP_BOOL("xreito", RISCVCPU, cfg.ext_XReito, false),

ISA_EXT_DATA_ENTRY(xreito, true, PRIV_VERSION_1_12_0, ext_XReito),
```

- Add things to `translate.c`
```
MATERIALISE_EXT_PREDICATE(XReito); 

/* Reito */
#include "decode-XReito.c.inc"
#include "insn_trans/trans_xreito.c.inc"

static const struct {
    bool (*guard_func)(DisasContext *);
    bool (*decode_func)(DisasContext *, uint32_t);
} decoders[] = {
    { always_true_p,  decode_insn32 },
    { has_XReito_p,  decode_XReito },
    { has_XVentanaCondOps_p,  decode_XVentanaCodeOps },
}; 
```

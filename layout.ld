PHDRS
{
  headers PT_PHDR PHDRS;
  interp PT_INTERP;
  text PT_LOAD FILEHDR PHDRS;
  data PT_LOAD;
  dynamic PT_DYNAMIC;
}

SECTIONS
{
  . = SEGMENT_START("text-segment", 0x400000);

  .interp : { *(.interp) } :text :interp
  .note.gnu.build-id : { *(.note.gnu.build-id) } :text
  .hash : { *(.hash) } :text
  .gnu.hash : { *(.gnu.hash) } :text
  .dynsym : { *(.dynsym) } :text
  .dynstr : { *(.dynstr) } :text
  .gnu.version : { *(.gnu.version) } :text
  .gnu.version_r : { *(.gnu.version_r) } :text
  .rela.dyn : { *(.rela.dyn) } :text
  .rela.plt : { *(.rela.plt) } :text
  .init : { *(.init) } :text
  .plt : { *(.plt) } :text
  .plt.got : { *(.plt.got) } :text

  .text : { 
    *(.text.main)
    *(.text.startup)
    *(.text)
  } :text

  . = 0x401337;
  .text.secret : {
    *(.text.secret)
  } :text

  .text.rest : {
    *(.text*)
  } :text

  .fini : { *(.fini) } :text
  .rodata : { *(.rodata) } :text
  .eh_frame_hdr : { *(.eh_frame_hdr) } :text
  .eh_frame : { KEEP (*(.eh_frame)) } :text

  . = DATA_SEGMENT_ALIGN(CONSTANT (MAXPAGESIZE), CONSTANT (COMMONPAGESIZE));

  .data : {
    *(.data)
    *(.data.*)
  } :data

  .dynamic : { *(.dynamic) } :data :dynamic
  .got : { *(.got) } :data
  .got.plt : { *(.got.plt) } :data
  
  .bss : { 
    *(.bss)
    *(.bss.*)
    *(COMMON)
  } :data
}
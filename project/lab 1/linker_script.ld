ENTRY(reset)

MEMORY
{
	Mem (rwx):ORIGIN = 0x00000000  , LENGTH = 64M
}

SECTIONS
{
	.startup :
	{
	  startup.o(.text)
	}>Mem
	.text :
	{
	*(.text)
	}>Mem
	.bss :
	{
	*(.bss)
	}>Mem
	.data :
	{
	*(.data)
	}>Mem
}


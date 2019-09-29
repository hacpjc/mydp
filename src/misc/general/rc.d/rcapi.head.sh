rccmd="$0"
rcname="`basename $rccmd`"
rcaction="$1"

function msg()
{
	echo "$rcname: $*"
}

function errmsg()
{
	echo "$rcname:ERROR: $*"
}

function abort()
{
	echo "$rcname: $*"
	echo "...abort"
	exit 255
}

#;

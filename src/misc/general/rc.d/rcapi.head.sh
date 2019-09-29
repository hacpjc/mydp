rccmd="$0"
rcname="`basename $rccmd`"
rcaction="$1"

function msg()
{
	echo "$rcname: $*"
}

function errmsg()
{
	echo " * ERROR:$rcname: $*"
}

function abort()
{
	echo " *** Abort:$rcname: $*"
	echo "...abort"
	exit 255
}

#;

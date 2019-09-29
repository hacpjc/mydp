rcpath="`dirname $0`"
rcpfx=${rcpath:-}
source "$rcpfx/rcapi.head.sh"

case "$rcaction" in
start)
	start
	;;
stop)
	stop
	;;
*)
	abort "Invalid argument: Try $rccmd <start|stop>"
	;;
esac

#;

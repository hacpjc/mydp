#!/bin/sh

rcpath="`dirname $0`"
rcpfx=${rcpath:-}/rc.d
test -d $rcpfx || (echo "BUG: FIXME"; exit 255;)
source "$rcpfx/rcapi.head.sh"

case "$rcaction" in
"start")
	list="`ls $rcpfx/rc.*.sh | sort`"
	for f in $list; do
		msg "Running:" `basename "$f"`
		sh "$f" $rcaction
	done
	;;
"stop")
	list="`ls $rcpfx/rc.*.sh | sort -r`"
	for f in $list; do
		msg "Running:" `basename "$f"`
		sh "$f" $rcaction
	done
	;;
*)
	abort "Invalid option: Try $0 <start|stop>"
	;;
esac

exit 0
#;

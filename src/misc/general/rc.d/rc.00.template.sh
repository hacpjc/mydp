#!/bin/sh
rcpath="`dirname $0`"
rcpfx=${rcpath:-}
source "$rcpfx/rcapi.head.sh"

function start()
{
	date
}

function stop()
{
	date
}

source "$rcpfx/rcapi.tail.sh"
#;

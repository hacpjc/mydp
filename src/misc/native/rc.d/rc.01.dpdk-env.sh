#!/bin/sh
rcpath="`dirname $0`"
rcpfx=${rcpath:-}
source "$rcpfx/rcapi.head.sh"

page2m_nr="256"
hugetlbfs_path="/mnt/huge"

function start()
{
	#
	# configure huge page sz
	#
	msg "set 2M page nr: $page2m_nr"
	echo $page2m_nr > /sys/kernel/mm/hugepages/hugepages-2048kB/nr_hugepages || abort "Cannot modify page num"

	#
	# mount hugetlbfs
	#
	test -d $hugetlbfs_path || mkdir $hugetlbfs_path || abort "Cannot create dir $hugetlbfs_path"

	msg "mount hugetlbfs to $hugetlbfs_path"
	mount -t hugetlbfs nodev $hugetlbfs_path || abort "Cannot mount hugetlbfs"
}

function stop()
{
	msg "umount hugetlbfs"
	umount $hugetlbfs_path
}

source "$rcpfx/rcapi.tail.sh"
#;

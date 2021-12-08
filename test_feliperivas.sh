#!/bin/bash

ours=$(echo "env" | ./hsh);
sh=$(echo "env" | sh);

if ["${ours}" == "${sh}" ]
then
	echo check 0 ok
else
	echo check 0 fail
fi

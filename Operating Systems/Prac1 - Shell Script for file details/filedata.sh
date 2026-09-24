#!/bin/bash

echo "Disk Usage Details"
echo ""

printf "%-20s %-10s %-10s %-12s %-8s %-20s\n" \
"Filesystem" "Total" "Used" "Available" "Use%" "Mounted On"

echo ""

df -hP | awk 'NR > 1 {
    printf "%-20s %-10s %-10s %-12s %-8s %-20s\n", $1, $2, $3, $4, $5, $6
}'

echo ""
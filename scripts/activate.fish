#!/usr/bin/fish

# Find the root git directory
set root_dir (git rev-parse --show-toplevel)
set script_dir $root_dir/scripts

# Check if script_dir is non-empty
if test -n "$script_dir"
    # Add root_dir/scripts/ to PATH
    if not contains $script_dir $PATH
        set -gx PATH $script_dir $PATH
    end
    ulimit -s 1048576 # 1G stack limit
    echo "Activated OI env. `run`, `run-debug`, `run-with-aclib` now available."
else
    echo "Not inside a Git repository."
end

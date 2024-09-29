#!/usr/bin/fish

# Find the root git directory
set root_dir (git rev-parse --show-toplevel)

# Check if root_dir is non-empty
if test -n "$root_dir"
    # Add root_dir/scripts/ to PATH
    set -gx PATH $root_dir/scripts $PATH
    echo "Activated OI env. `run`, `run-debug`, `run-with-aclib` now available."
else
    echo "Not inside a Git repository."
end

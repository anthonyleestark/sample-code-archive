# Comment Auto-replace for Multiple Files

import os
import re

def clean_comment_block(block, tag):
    lines = block.strip().splitlines()
    content = {}
    current_key = None

    for line in lines:
        stripped = line.strip(" /")  # remove leading/trailing slashes and spaces
        if not stripped:
            continue
        if stripped.startswith(f"[{tag}]"):
            continue

        # Match "Key: Value" pattern
        match = re.match(r"^([A-Za-z ]+):\s*(.*)", stripped)
        if match:
            current_key = match.group(1).strip().lower()
            content[current_key] = match.group(2).rstrip()
        elif current_key:
            # Append continuation line with a newline
            content[current_key] += "\n" + stripped

    # Generate Doxygen block
    doxy = "/**\n"
    if tag == "FUNCTION":
        doxy += f" * @function {content.get('function name', 'UnnamedFunction')}\n"
        if "description" in content:
            desc_lines = content["description"].splitlines()
            if desc_lines:
                doxy += f" * @brief {desc_lines[0]}\n"
                for line in desc_lines[1:]:
                    doxy += f" * {line}\n"
        if "arguments" in content:
            for line in content["arguments"].splitlines():
                doxy += f" * @param {line}\n"
        if "return value" in content:
            for line in content["return value"].splitlines():
                doxy += f" * @return {line}\n"

    elif tag == "CLASS":
        doxy += f" * @class {content.get('class name', 'UnnamedClass')}\n"
        if "description" in content:
            for line in content["description"].splitlines():
                doxy += f" * @brief {line}\n"

    elif tag == "FILE-HEADER":
        doxy += f" * @file {content.get('file name', 'UnknownFile')}\n"
        if "description" in content:
            for i, line in enumerate(content["description"].splitlines()):
                doxy += f" * @brief {line}\n" if i == 0 else f" *        {line}\n"
        if "owner" in content:
            doxy += f" * @author {content['owner']}\n"
        if "history" in content:
            for line in content["history"].splitlines():
                doxy += f" * @history {line}\n"
                
    elif tag == "DATA-TYPE":
        if "description" in content:
            for i, line in enumerate(content["description"].splitlines()):
                doxy += f" * @brief {line}\n" if i == 0 else f" *        {line}\n"        

    else:
        doxy += f" * @note Untagged or unsupported tag: {tag}\n"

    doxy += " */"
    return doxy

def build_tagged_block_pattern(tag, min_slash_count=10):
    # Match a block with at least N slashes and a line containing [TAG]
    return re.compile(
        rf"(\/{{{min_slash_count},}}\n(?:(?!\/{{{min_slash_count},}})(?:.|\n))*\[\s*{tag}\s*\](?:(?!\/{{{min_slash_count},}})(?:.|\n))*\/{{{min_slash_count},}})",
        re.MULTILINE
    )

def replace_in_file(filepath, tag="FUNC", min_slash_count=10):
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()

    pattern = build_tagged_block_pattern(tag, min_slash_count)
    matches = list(pattern.finditer(content))

    for match in reversed(matches):
        match_start, match_end = match.span()
        original_block = match.group(0)
        new_block = clean_comment_block(original_block, tag)
        content = content[:match_start] + new_block + content[match_end:]

    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)

def replace_in_directory(root_dir, tag="FUNC", extensions=(".cpp", ".h", ".inl"), min_slash_count=10):
    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith(extensions):
                full_path = os.path.join(dirpath, filename)
                replace_in_file(full_path, tag=tag, min_slash_count=min_slash_count)
                print(f"Processed [{tag}]: {full_path}")

# Usage:
replace_in_directory("path/to/your/source/folder", tag="FUNCTION", min_slash_count=70)
replace_in_directory("path/to/your/source/folder", tag="CLASS", min_slash_count=70)
replace_in_directory("path/to/your/source/folder", tag="FILE-HEADER", min_slash_count=70)
replace_in_directory("path/to/your/source/folder", tag="DATA-TYPE", min_slash_count=70)

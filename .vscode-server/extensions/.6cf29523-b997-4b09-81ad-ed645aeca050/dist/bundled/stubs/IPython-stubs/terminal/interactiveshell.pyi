"""
This type stub file was generated by pyright.
"""

from typing import Union as UnionType
from IPython.core.interactiveshell import InteractiveShell
from traitlets import Integer, observe
from prompt_toolkit.auto_suggest import AutoSuggestFromHistory
from prompt_toolkit.history import History
from prompt_toolkit.shortcuts import PromptSession
from pygments.style import Style
from .shortcuts.auto_suggest import NavigableAutoSuggestFromHistory

"""IPython terminal interface using prompt_toolkit"""
PTK3 = ...
class _NoStyle(Style):
    ...


_style_overrides_light_bg = ...
_style_overrides_linux = ...
def get_default_editor():
    ...

_use_simple_prompt = ...
def black_reformat_handler(text_before_cursor):
    """
    We do not need to protect against error,
    this is taken care at a higher level where any reformat error is ignored.
    Indeed we may call reformatting on incomplete code.
    """
    ...

def yapf_reformat_handler(text_before_cursor):
    ...

class PtkHistoryAdapter(History):
    """
    Prompt toolkit has it's own way of handling history, Where it assumes it can
    Push/pull from history.

    """
    def __init__(self, shell) -> None:
        ...
    
    def append_string(self, string): # -> None:
        ...
    
    def load_history_strings(self):
        ...
    
    def store_string(self, string: str) -> None:
        ...
    


class TerminalInteractiveShell(InteractiveShell):
    mime_renderers = ...
    space_for_menu = Integer(6, help='Number of line at the bottom of the screen ' 'to reserve for the tab completion menu, ' 'search history, ...etc, the height of ' 'these menus will at most this value. ' 'Increase it is you prefer long and skinny ' 'menus, decrease for short and wide.').tag(config=True)
    pt_app: UnionType[PromptSession, None] = ...
    auto_suggest: UnionType[AutoSuggestFromHistory, NavigableAutoSuggestFromHistory, None] = ...
    debugger_history = ...
    debugger_history_file = ...
    simple_prompt = ...
    @property
    def debugger_cls(self): # -> Type[Pdb] | Type[TerminalPdb]:
        ...
    
    confirm_exit = ...
    editing_mode = ...
    emacs_bindings_in_vi_insert_mode = ...
    modal_cursor = ...
    ttimeoutlen = ...
    timeoutlen = ...
    autoformatter = ...
    auto_match = ...
    mouse_support = ...
    highlighting_style = ...
    def refresh_style(self): # -> None:
        ...
    
    highlighting_style_overrides = ...
    true_color = ...
    editor = ...
    prompts_class = ...
    prompts = ...
    term_title = ...
    term_title_format = ...
    display_completions = ...
    highlight_matching_brackets = ...
    extra_open_editor_shortcuts = ...
    handle_return = ...
    enable_history_search = ...
    autosuggestions_provider = ...
    shortcuts = ...
    prompt_includes_vi_mode = ...
    @observe('term_title')
    def init_term_title(self, change=...): # -> None:
        ...
    
    def restore_term_title(self): # -> None:
        ...
    
    def init_display_formatter(self): # -> None:
        ...
    
    def init_prompt_toolkit_cli(self): # -> None:
        ...
    
    @property
    def pt_complete_style(self):
        ...
    
    @property
    def color_depth(self): # -> Literal[ColorDepth.TRUE_COLOR] | None:
        ...
    
    def prompt_for_code(self):
        ...
    
    def enable_win_unicode_console(self): # -> None:
        ...
    
    def init_io(self): # -> None:
        ...
    
    def init_magics(self): # -> None:
        ...
    
    def init_alias(self): # -> None:
        ...
    
    def __init__(self, *args, **kwargs) -> None:
        ...
    
    def ask_exit(self): # -> None:
        ...
    
    rl_next_input = ...
    def interact(self): # -> None:
        ...
    
    def mainloop(self): # -> None:
        ...
    
    _inputhook = ...
    def inputhook(self, context): # -> None:
        ...
    
    active_eventloop = ...
    def enable_gui(self, gui=...): # -> None:
        ...
    
    system = ...
    def auto_rewrite_input(self, cmd): # -> None:
        """Overridden from the parent class to use fancy rewriting prompt"""
        ...
    
    _prompts_before = ...
    def switch_doctest_mode(self, mode): # -> None:
        """Switch prompts to classic for %doctest_mode"""
        ...
    


if __name__ == '__main__':
    ...

set number
set mouse=a
set numberwidth=1
set clipboard
syntax enable
set showcmd
set ruler
set encoding=utf-8
set showmatch
set tabstop=8 shiftwidth=8
set autoindent
set smartindent
set cindent


call plug#begin('~/.vim/plugged')

Plug 'scrooloose/nerdtree'
Plug 'christoomey/vim-tmux-navigator'
Plug 'Shougo/deoplete.nvim', { 'do': ':UpdateRemotePlugins' }
Plug 'Shougo/neco-syntax'  " Fuente general de auto completado
Plug 'ervandew/supertab'
Plug 'Shougo/echodoc.vim'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'  " Temas para airline
Plug 'sirver/ultisnips'
Plug 'honza/vim-snippets'
"" icons 
Plug 'ryanoasis/vim-devicons'

call plug#end()

let mapleader=" "

map <Leader>m :NERDTreeToggle<CR>
nmap <Leader>w :w<CR>
nmap <Leader>q :q<CR>
nmap <Leader>c :!

" Activar deoplete al iniciar Neovim
let g:deoplete#enable_at_startup = 1

" Cerrar automaticamente la ventana de vista previa (donde se muestra documentación, si existe)
augroup deopleteCompleteDoneAu
  autocmd!
  autocmd CompleteDone * silent! pclose!
augroup END

" Invertir direccion de navegacion (de arriba a abajo)
let g:SuperTabDefaultCompletionType = '<c-n>'

set noshowmode  " No mostrar el modo actual (echodoc hace uso de este espacio)

" Activar echodoc al iniciar Neovim
let g:echodoc_enable_at_startup = 1

let g:airline#extensions#tabline#enabled = 1  " Mostrar buffers abiertos (como pestañas)
let g:airline#extensions#tabline#fnamemod = ':t'  " Mostrar sólo el nombre del archivo

" Cargar fuente Powerline y símbolos (ver nota)
let g:airline_powerline_fonts = 1

set noshowmode  " No mostrar el modo actual (ya lo muestra la barra de estado)

" Expandir snippet con Ctrl + j
map <Leader>s :UltiSnipsExpandTrigger<CR>
"let g:UltiSnipsExpandTrigger = '<c-j>'

" Ir a siguiente ubicacion con Ctrl + j
let g:UltiSnipsJumpForwardTrigger = '<c-j>'
" Ir a anterior ubicacion con Ctrl + k
let g:UltiSnipsJumpBackwardTrigger = '<c-k>'

" loading the plugin
let g:webdevicons_enable = 1
" adding the flags to NERDTree
let g:webdevicons_enable_nerdtree = 1

/* See LICENSE file for copyright and license details. */

/* My configs */

//BAR_SYSTRAY_PATCH
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */

//AUTOSTART_PATCH
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "dwm";
static const char localshare[]           = ".local/share";

//BAR_HEIGHT_PATCH
static const int bar_height              = 26;   /* 0 means derive from font, >= 1 explicit height */

// ALT_TAB_PATCH
static const unsigned int tabmodkey        = 0x40; /* (Alt) when this key is held down the alt-tab functionality stays active. Must be the same modifier as used to run alttabstart */
static const unsigned int tabcyclekey      = 0x17; /* (Tab) when this key is hit the menu moves one position forward in client stack. Must be the same key as used to run alttabstart */
static const unsigned int tabposy          = 1;    /* tab position on Y axis, 0 = top, 1 = center, 2 = bottom */
static const unsigned int tabposx          = 1;    /* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxwtab          = 600;  /* tab menu width */
static const unsigned int maxhtab          = 200;  /* tab menu height */


static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;

#if NAMETAG_PATCH
static char tagicons[][NUMTAGS][MAX_TAGLEN] =
#else
static char *tagicons[][NUMTAGS] =
#endif // NAMETAG_PATCH
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

//MONOCLE_LAYOUT
static void (*bartabmonfns[])(Monitor *) = { monocle /* , customlayoutfn */ };

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";

#if RENAMED_SCRATCHPADS_PATCH
static char scratchselfgcolor[]          = "#FFF7D4";
static char scratchselbgcolor[]          = "#77547E";
static char scratchselbordercolor[]      = "#894B9F";
static char scratchselfloatcolor[]       = "#894B9F";

static char scratchnormfgcolor[]         = "#FFF7D4";
static char scratchnormbgcolor[]         = "#664C67";
static char scratchnormbordercolor[]     = "#77547E";
static char scratchnormfloatcolor[]      = "#77547E";
#endif // RENAMED_SCRATCHPADS_PATCH

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
	#if RENAMED_SCRATCHPADS_PATCH
	[SchemeScratchSel]  = { scratchselfgcolor, scratchselbgcolor, scratchselbordercolor, scratchselfloatcolor },
	[SchemeScratchNorm] = { scratchnormfgcolor, scratchnormbgcolor, scratchnormbordercolor, scratchnormfloatcolor },
	#endif // RENAMED_SCRATCHPADS_PATCH
};

#if RENAMED_SCRATCHPADS_PATCH
static const char *scratchpadcmd[] = {"s", "alacritty", "--class", "spterm", NULL};
#endif //RENAMED_SCRATCHPADS_PATCH

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	#if RENAMED_SCRATCHPADS_PATCH
	RULE(.instance = "spterm", .scratchkey = 's', .isfloating = 1)
	#elif SCRATCHPADS_PATCH
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
	#endif // SCRATCHPADS_PATCH
};

static const Layout layouts[] = {
	/* symbol     arrange function */
	#if TILE_LAYOUT
	{ "[]=",      tile },    /* first entry is default */
	#endif
	{ "><>",      NULL },    /* no layout function means floating behavior */
	#if MONOCLE_LAYOUT
	{ "[M]",      monocle },
	#endif
	#if BSTACK_LAYOUT
	{ "TTT",      bstack },
	#endif
	#if BSTACKHORIZ_LAYOUT
	{ "===",      bstackhoriz },
	#endif
	#if CENTEREDMASTER_LAYOUT
	{ "|M|",      centeredmaster },
	#endif
	#if CENTEREDFLOATINGMASTER_LAYOUT
	{ ">M>",      centeredfloatingmaster },
	#endif
	#if COLUMNS_LAYOUT
	{ "|||",      col },
	#endif
	#if DECK_LAYOUT
	{ "[D]",      deck },
	#endif
	#if FIBONACCI_SPIRAL_LAYOUT
	{ "(@)",      spiral },
	#endif
	#if FIBONACCI_DWINDLE_LAYOUT
	{ "[\\]",     dwindle },
	#endif
	#if GRIDMODE_LAYOUT
	{ "HHH",      grid },
	#endif
	#if HORIZGRID_LAYOUT
	{ "---",      horizgrid },
	#endif
	#if GAPPLESSGRID_LAYOUT
	{ ":::",      gaplessgrid },
	#endif
	#if NROWGRID_LAYOUT
	{ "###",      nrowgrid },
	#endif
};

#if BAR_STATUSCMD_PATCH
#if BAR_DWMBLOCKS_PATCH
/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"
#else
/* commands spawned when clicking statusbar, the mouse button pressed is exported as BUTTON */
static const StatusCmd statuscmds[] = {
	{ "notify-send Volume$BUTTON", 1 },
	{ "notify-send CPU$BUTTON", 2 },
	{ "notify-send Battery$BUTTON", 3 },
};
/* test the above with: xsetroot -name "$(printf '\x01Volume |\x02 CPU |\x03 Battery')" */
static const char *statuscmd[] = { "/usr/bin/env", "sh", "-c", NULL, NULL };
#endif // BAR_DWMBLOCKS_PATCH
#endif // BAR_STATUSCMD_PATCH

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };


/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/usr/bin/env", "sh", "-c", cmd, NULL } }

/* commands */
#if !NODMENU_PATCH
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
#endif // NODMENU_PATCH
static const char *dmenucmd[]  = { "$HOME/.local/bin/dm-run", NULL };
static const char *dmrun[]     = { "$HOME/.local/bin/dm-run", NULL };
static const char *dmoffload[] = { "$HOME/dm-offload"       , NULL };
static const char *termcmd[]   = { "alacritty", "-e", "tmux", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmoffload } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = dmrun   } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	#if TAB_PATCH
	{ MODKEY|ControlMask,           XK_b,          tabmode,                {-1} },
	#endif // TAB_PATCH
	#if FOCUSMASTER_PATCH
	{ MODKEY|ControlMask,           XK_space,      focusmaster,            {0} },
	#endif // FOCUSMASTER_PATCH
	#if MOVERESIZE_PATCH
	{ MODKEY|Mod1Mask,              XK_Down,       moveresize,             {.v = "0x 25y 0w 0h" } },
	{ MODKEY|Mod1Mask,              XK_Up,         moveresize,             {.v = "0x -25y 0w 0h" } },
	{ MODKEY|Mod1Mask,              XK_Right,      moveresize,             {.v = "25x 0y 0w 0h" } },
	{ MODKEY|Mod1Mask,              XK_Left,       moveresize,             {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_Down,       moveresize,             {.v = "0x 0y 0w 25h" } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_Up,         moveresize,             {.v = "0x 0y 0w -25h" } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_Right,      moveresize,             {.v = "0x 0y 25w 0h" } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_Left,       moveresize,             {.v = "0x 0y -25w 0h" } },
	#endif // MOVERESIZE_PATCH
	#if ALT_TAB_PATCH
	{ Mod1Mask,                     XK_Tab,        alttabstart,            {0} },
	#else
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	#endif // ALT_TAB_PATCH
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,                       XK_space,  setlayout,      {0} },
  { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	#if MAXIMIZE_PATCH
	{ MODKEY|ControlMask|ShiftMask, XK_h,          togglehorizontalmax,    {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_l,          togglehorizontalmax,    {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_j,          toggleverticalmax,      {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_k,          toggleverticalmax,      {0} },
	{ MODKEY|ControlMask,           XK_m,          togglemax,              {0} },
	#endif // MAXIMIZE_PATCH
	#if TOGGLEFULLSCREEN_PATCH
	{ MODKEY,                       XK_y,          togglefullscreen,       {0} },
	#endif // TOGGLEFULLSCREEN_PATCH
	#if FULLSCREEN_PATCH
	{ MODKEY|ShiftMask,             XK_f,          fullscreen,             {0} },
	#endif // FULLSCREEN_PATCH
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_z,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	#if BAR_STATUSBUTTON_PATCH
	{ ClkButton,            0,                   Button1,        spawn,          {.v = dmenucmd } },
	#endif // BAR_STATUSBUTTON_PATCH
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	#if BAR_LAYOUTMENU_PATCH
	{ ClkLtSymbol,          0,                   Button3,        layoutmenu,     {0} },
	#else
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	#endif // BAR_LAYOUTMENU_PATCH
	#if BAR_WINTITLEACTIONS_PATCH
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	#endif // BAR_WINTITLEACTIONS_PATCH
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	#if BAR_STATUSCMD_PATCH && BAR_DWMBLOCKS_PATCH
	{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },
	#elif BAR_STATUSCMD_PATCH
	{ ClkStatusText,        0,                   Button1,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,                   Button3,        spawn,          {.v = statuscmd } },
	#else
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	#endif // BAR_STATUSCMD_PATCH
	#if PLACEMOUSE_PATCH
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,         MODKEY,              Button1,        moveorplace,    {.i = 1} },
	#else
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	#endif // PLACEMOUSE_PATCH
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	#if TAPRESIZE_PATCH
	{ ClkClientWin,         MODKEY,              Button4,        resizemousescroll, {.v = &scrollargs[0]} },
	{ ClkClientWin,         MODKEY,              Button5,        resizemousescroll, {.v = &scrollargs[1]} },
	{ ClkClientWin,         MODKEY,              Button6,        resizemousescroll, {.v = &scrollargs[2]} },
	{ ClkClientWin,         MODKEY,              Button7,        resizemousescroll, {.v = &scrollargs[3]} },
	#endif // TAPRESIZE_PATCH
	#if DRAGCFACT_PATCH && CFACTS_PATCH
	{ ClkClientWin,         MODKEY|ShiftMask,    Button3,        dragcfact,      {0} },
	#endif // DRAGCFACT_PATCH
	#if DRAGMFACT_PATCH
	{ ClkClientWin,         MODKEY|ShiftMask,    Button1,        dragmfact,      {0} },
	#endif // DRAGMFACT_PATCH
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
	#if TAB_PATCH
	{ ClkTabBar,            0,                   Button1,        focuswin,       {0} },
	#endif // TAB_PATCH
};

static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	#if BAR_STATUSBUTTON_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_stbutton,           draw_stbutton,          click_stbutton,          NULL,                    "statusbutton" },
	#endif // BAR_STATUSBUTTON_PATCH
	#if BAR_POWERLINE_TAGS_PATCH
	{  0,        0,     BAR_ALIGN_LEFT,   width_pwrl_tags,          draw_pwrl_tags,         click_pwrl_tags,         NULL,                    "powerline_tags" },
	#endif // BAR_POWERLINE_TAGS_PATCH
	#if BAR_TAGS_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	#endif // BAR_TAGS_PATCH
	#if BAR_TAGLABELS_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_taglabels,          draw_taglabels,         click_taglabels,         NULL,                    "taglabels" },
	#endif // BAR_TAGLABELS_PATCH
	#if BAR_TAGGRID_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_taggrid,            draw_taggrid,           click_taggrid,           NULL,                    "taggrid" },
	#endif // BAR_TAGGRID_PATCH
	#if BAR_SYSTRAY_PATCH
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	#endif // BAR_SYSTRAY_PATCH
	#if BAR_LTSYMBOL_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	#endif // BAR_LTSYMBOL_PATCH
	#if XKB_PATCH
	{  0,        0,     BAR_ALIGN_RIGHT,  width_xkb,                draw_xkb,               click_xkb,               NULL,                    "xkb" },
	#endif // XKB_PATCH
	#if BAR_FLEXWINTITLE_PATCH
	{ -1,        0,     BAR_ALIGN_NONE,   width_flexwintitle,       draw_flexwintitle,      click_flexwintitle,      NULL,                    "flexwintitle" },
	#elif BAR_TABGROUPS_PATCH
	{ -1,        0,     BAR_ALIGN_NONE,   width_bartabgroups,       draw_bartabgroups,      click_bartabgroups,      NULL,                    "bartabgroups" },
	#elif BAR_AWESOMEBAR_PATCH
	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,         draw_awesomebar,        click_awesomebar,        NULL,                    "awesomebar" },
	#elif BAR_FANCYBAR_PATCH
	{ -1,        0,     BAR_ALIGN_NONE,   width_fancybar,           draw_fancybar,          click_fancybar,          NULL,                    "fancybar" },
	#elif BAR_WINTITLE_PATCH
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
	#endif // BAR_TABGROUPS_PATCH | BAR_AWESOMEBAR_PATCH | BAR_FANCYBAR_PATCH | BAR_WINTITLE_PATCH
	#if BAR_FLEXWINTITLE_PATCH
	#if BAR_WINTITLE_HIDDEN_PATCH
	{ -1,        1,  BAR_ALIGN_RIGHT_RIGHT, width_wintitle_hidden,  draw_wintitle_hidden,   click_wintitle_hidden,   NULL,                    "wintitle_hidden" },
	#endif
	#if BAR_WINTITLE_FLOATING_PATCH
	{ -1,        1,     BAR_ALIGN_LEFT,   width_wintitle_floating,  draw_wintitle_floating, click_wintitle_floating, NULL,                    "wintitle_floating" },
	#endif // BAR_WINTITLE_FLOATING_PATCH
	#endif // BAR_FLEXWINTITLE_PATCH
};

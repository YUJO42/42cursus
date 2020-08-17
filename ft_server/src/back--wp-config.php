<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'wordpress_user' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

define('FS_METHOD', 'direct');

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
/**#@-*/
define('AUTH_KEY',         'z,k*y_-nrk}&*06|Ir~g8Igp.}s{fQE4#7e8D6{DRcwV!KWhMBrw&^g}AmTRUJ9k');                                                                                           define('SECURE_AUTH_KEY',  'D>mRoz;g:r-e*p8#CX@hLjBVAIW/.r[tO z6P0XHHOHU(r{EAy4:4?Zko=r@k{D7');                                                                                           define('LOGGED_IN_KEY',    '!!:^#/a`MK84Mx) `5lwkL{=Tz<v9(l`HR[P-qi^f-I%NSvaCh2R-T.{uM73}?S|');                                                                                           define('NONCE_KEY',        'goG-do4Z|! { I48>d)DukTJU@r`4B@LN^kcs7g{2-vwkG$g}];` lV#,CYd47*r');                                                                                           define('AUTH_SALT',        'B^K &e+MS`2$/AILa2Vx(5(^4gZayy?@):|H.S]hv1lYj&2GRC~0[w$X$mQv{AI+');                                                                                           define('SECURE_AUTH_SALT', 'nxkvi4_+0+lF#<2oDa7>?_g;b[^-x4[Yu}Yd63(3D=T[v][h B%WzNu=mOZ-uDp$');                                                                                           define('LOGGED_IN_SALT',   '6U)X&I{ndPyL_z3<CH3L;j]0V@c-gVT*n?#8tEmGW-6g:q=KT4MK3=I!&1/x)]2e');                                                                                           define('NONCE_SALT',       'O{V=Jj:weU&9XH~C(+KSg+J0*n+qC!ixF_h+sgK6_G2rL5(WClayWA3gw2-j|xWl');            
/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
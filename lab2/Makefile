# $Id: Makefile,v 1.1 2014-01-19 19:18:51-08 - - $

JAVASRC    = exit255.java
SOURCES    = ${JAVASRC} Makefile
MAINCLASS  = exit255
CLASSES    = exit255.class
JARFILE    = exit255
JARCLASSES = ${CLASSES}

all: ${JARFILE}

${JARFILE}: ${CLASSES}
	echo Main-class: ${MAINCLASS} >Manifest
	jar cvfm ${JARFILE} Manifest ${JARCLASSES}
	- rm -vf Manifest
	chmod +x ${JARFILE}

%.class: %.java
	javac $<

clean:
	-rm -vf ${CLASSES} 255.output

spotless: clean
	-rm -vf ${JARFILE}

ci: ${SOURCES}
	cid + ${SOURCES}
	- checksource ${SOURCES}

test: ${JARFILE}
	( echo "%%%%%%%% ${JARFILE}" \
	; ${JARFILE} 2>&1 \
	; echo "%%%%%%%% Exit status = $$?" \
	; echo "%%%%%%%% uname -a" ; uname -a | sed 's/#/\n#/' \
	) >255.output
	cat -nv 255.output

again:
	gmake --no-print-directory spotless ci all test


